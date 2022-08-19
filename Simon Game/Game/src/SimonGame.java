// SIMON GAME
// Fully written by Claudio Osorio
// April 4th, 2022


import javax.imageio.ImageIO;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;


public class SimonGame
{
    static Thread waitForInput;
    ScheduledExecutorService scheduler = Executors.newSingleThreadScheduledExecutor();
    Future<?> expectedDefeatTask;

    // Runnable task to end game
    Runnable defeat = new Runnable() {
        @Override
        public void run() {
            if (!win && !lose)
            {
                lose = true;
            }
        }
    };

    // Used to create a non-blocking instance in a different thread
    // so that the player can "repeat"/rewatch the sequence asynchronously
    static ScheduledExecutorService schedulerRepeatLastSequence = Executors.newSingleThreadScheduledExecutor();
    static Future<?> lastSequenceRepeater;
    Runnable lastSeqRun = new Runnable() {
        @Override
        public void run() {
            RepeatLastSequence();
        }
    };

    // Setting Game UI Elements
    static JFrame gameFrame;
    static JLayeredPane gamePane;
    static JButton buttonGreen;
    static JButton buttonYellow;
    static JButton buttonBlue;
    static JButton buttonRed;
    static JButton buttonLastSequence;

    static JLabel scoreText;
    static JLabel simonText;
    static JLabel highscoreText;

    // Previous & stored high score info
    static String highScorePlayer = "Player1";
    static int highScore = 0 ;

    // Current player score info
    static String currentScorePlayer = "Player1";
    static int currentScore = 0;

    // Game logic Info
    static final int MaximumNumberOfTurns = 15;
    static int currentTurn = 0;                 // Indicates the current turn
    static boolean sequenceMode = false;        // Flag for when game teaches sequence to player
    static boolean repeatingSequence = false;   // Flag for during sequence repetition
    static boolean win = false;                 // Flag for when the game is won
    static boolean lose = false;                // Flag for when game is lost
    static boolean GameInPlay = false;          // Flag for when game is in play

    Random randomSequenceGenerator;
    static ArrayList<Integer> sequence = new ArrayList<>();
    static ArrayList<Integer> repeatSequence = new ArrayList<>();

    // Pre-set settings. Options to choose from for the interval between signals.
    private static final int [][] IntervalBetweenSignals = new int[][]{
            {1500,1300,1100,900},
            {1100,1000,900,800},
            {900,700,500,400}
    };

    static final int [] MaximumInputWaitTime =new int[] {4000,3000,2000};

    static long playerAllottedTime;         //Time allotted in milliseconds (as Long)
    static int gameAllottedTime = 0;        // Time allotted for player to move in milliseconds
    static int gameInterval = 0;            // Time interval between signals in milliseconds


    // CONSTRUCTOR
    public SimonGame(JFrame gameWindow, int interval, int allottedTime, String playerName)
    {
        // Game Settings
        gameInterval = interval;
        gameAllottedTime = allottedTime;
        currentScorePlayer = playerName;

        // Game Logic
        lose = false;
        win = false;
        randomSequenceGenerator = new Random();
        gameFrame = gameWindow;
        playerAllottedTime = MaximumInputWaitTime[gameAllottedTime];
        setGameUI(gameFrame);
    }

    // Sets the visible panel - Inserts buttons and labels to UI
    private void setGameUI(JFrame frame)
    {
        gamePane = new JLayeredPane();

        buttonGreen = new JButton();
        buttonYellow = new JButton();
        buttonBlue = new JButton();
        buttonRed = new JButton();

        gamePane.setBounds(0,0,1000,1000);

        // Green, Yellow, Blue, Red Buttons
        buttonGreen.setBounds(0,0,500,500);
        buttonGreen.setBackground(Color.GREEN);
        buttonGreen.setVisible(true);
        buttonGreen.setFocusable(true);

        buttonYellow.setBounds(0,500,500,500);
        buttonYellow.setBackground(Color.YELLOW);
        buttonYellow.setVisible(true);
        buttonYellow.setFocusable(true);

        buttonBlue.setBounds(500,500,500,500);
        buttonBlue.setBackground(Color.BLUE);
        buttonBlue.setVisible(true);
        buttonBlue.setFocusable(true);

        buttonRed.setBounds(500,0,500,500);
        buttonRed.setBackground(Color.RED);
        buttonRed.setVisible(true);
        buttonRed.setFocusable(true);

        // Last sequence button
        buttonLastSequence = new JButton("REPEAT");
        buttonLastSequence.setBounds(525,525,80,50);
        buttonLastSequence.setForeground(Color.WHITE);
        buttonLastSequence.setBackground(Color.BLACK);
        buttonLastSequence.setVisible(true);
        buttonLastSequence.setFocusable(true);

        //UI Cover
        BufferedImage uiImg;
        try {
            uiImg = ImageIO.read(Objects.requireNonNull(SetupWindow.class.getResource("/Data/Images/ui.png")));
            final ImageIcon ui = new ImageIcon(uiImg);
            JLabel uiLabel = new JLabel();
            uiLabel.setIcon(ui);
            uiLabel.setSize(1000,1000);
            uiLabel.setFocusable(true);
            gamePane.add(uiLabel,Integer.valueOf(1));
        } catch (IOException e)
        {
            System.out.println("UI Image could not be found.");
            e.printStackTrace();
            System.exit(0);
        }

        // SIMON - Text
        simonText = new JLabel("SIMON");
        simonText.setFont(new Font("Verdana", Font.BOLD,80));
        simonText.setBounds(345,380,320,70);
        simonText.setVisible(true);
        simonText.setForeground(Color.WHITE);

        // Current Score - Text
        scoreText = new JLabel(String.valueOf(currentScore));
        scoreText.setFont(new Font(Font.DIALOG, Font.PLAIN,65));
        scoreText.setBounds(400,520,100,80);
        scoreText.setForeground(Color.GRAY);
        scoreText.setVisible(true);

        // High Score - Text
        highscoreText = new JLabel("<html>HIGH SCORE:</html>");
        highscoreText.setFont(new Font(Font.DIALOG, Font.BOLD,25));
        highscoreText.setBounds(20,3,250,120);
        highscoreText.setForeground(Color.WHITE);
        highscoreText.setVisible(true);

        // Adding buttons to panel
        gamePane.add(buttonGreen,Integer.valueOf(0));
        gamePane.add(buttonYellow,Integer.valueOf(0));
        gamePane.add(buttonBlue,Integer.valueOf(0));
        gamePane.add(buttonRed,Integer.valueOf(0));

        gamePane.add(simonText,Integer.valueOf(2));
        gamePane.add(scoreText,Integer.valueOf(2));
        gamePane.add(highscoreText,Integer.valueOf(2));
        gamePane.add(buttonLastSequence,Integer.valueOf(2));

        frame.add(gamePane);
        ButtonBehavior();
    }

    // Defining Button Behavior
    public void ButtonBehavior()
    {
        // GREEN
        buttonGreen.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (e.getSource()==buttonGreen && !win && !lose && GameInPlay)
                {
                    System.out.println("NOW: Playing Green");
                    // Play mp3
                    playWavSoundFile("green.wav");

                    ButtonLogic(1);
                }
            }
        });

        // YELLOW
        buttonYellow.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (e.getSource()==buttonYellow && !win && !lose && GameInPlay)
                {
                    System.out.println("NOW: Playing Yellow");
                    // Play mp3
                    playWavSoundFile("yellow.wav");

                    ButtonLogic(2);
                }
            }
        });

        // BLUE
        buttonBlue.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (e.getSource()==buttonBlue && !win && !lose && GameInPlay)
                {
                    System.out.println("NOW: Playing Blue");
                    // Play mp3
                    playWavSoundFile("blue.wav");
                    ButtonLogic(3);
                }
            }
        });

         // RED
        buttonRed.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if (e.getSource()==buttonRed && !win && !lose && GameInPlay)
                {
                    System.out.println("NOW: Playing Red");
                    // Play mp3
                    playWavSoundFile("red.wav");
                    ButtonLogic(4);
                }
            }
        });

        buttonLastSequence.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                lastSequenceRepeater = schedulerRepeatLastSequence.schedule(lastSeqRun,
                        0,
                        TimeUnit.MILLISECONDS);
            }
        });
    }

    // Id: 1 = Green, 2 = Yellow, 3 = Blue, 4 = Red
    private void ButtonLogic(int buttonID)
    {
        // If button is pressed automatically during sequence mode
        // then ignore input.
        if (sequenceMode)
        {
            // Do nothing. Let the game continue playing the sequence.
        }
        // if button is pressed correctly then add to score and cancel game over
        else if (!repeatSequence.isEmpty() && repeatSequence.get(0) == buttonID)
        {
            // Removes this button/signal from the sequence pending.
            repeatSequence.remove(0);

            // Add +1 to score and update visuals
            currentScore +=1;
            UpdateVisualScore();

            // If this is not the last button in the sequence due to be pressed
            // then restart game over timer, else cancel timer.
            expectedDefeatTask.cancel(true);
            if (!repeatSequence.isEmpty() && !lose && !win)
            {
                expectedDefeatTask = scheduler.schedule(defeat,
                        playerAllottedTime,
                        TimeUnit.MILLISECONDS);

            }

            // If there are no signals left to repeat in this turn then
            // cancel the time reserved for the player's turn
            if(repeatSequence.isEmpty())
            {
                waitForInput.interrupt();
            }
        }else
        {
            // Player Pressed this button incorrectly
            if (!win && !lose)
            {
                lose = true;
            }
        }
    }

    // Starts Game. Generates a random sequence of signals.  Plays the sequence according
    // to the current turn and then verifies it before moving on.
    public void StartGame()
    {
        if (gameAllottedTime == 0)
            System.out.println("NOW: Difficulty Selected \"EASY\"");
        if (gameAllottedTime == 1)
            System.out.println("NOW: Difficulty Selected \"MEDIUM\"");
        if (gameAllottedTime == 2)
            System.out.println("NOW: Difficulty Selected \"HARD\"");

        gameFrame.getContentPane().repaint();
        ResetGame();
        GameInPlay = true;
        StarCountdown();

        for (int i = 1; i < (MaximumNumberOfTurns + 1) && !lose && !win; i++)
        {
            currentTurn += 1;
            System.out.println("\nCurrent Turn: "+ currentTurn);
            try {
                PlaySequence(gameInterval);
                repeatSequence.clear();
                for (int x = 0; x < currentTurn; x++)
                {
                    repeatSequence.add(sequence.get(x));
                }

                // PLAYER TURN:
                //Assume player fails. Schedule defeat upon time expiration.
                expectedDefeatTask = scheduler.schedule(defeat,
                        playerAllottedTime,
                        TimeUnit.MILLISECONDS);

                System.out.println("NOW: EXPECTING PLAYER INPUT");
                // Sleeping until next turn but constantly checking to see if the player
                // finished repeating the sequence. As soon as the player completes the
                // sequence of this turn if it is correct then this cancels the leftover time
                // and lets the game move on to the next turn.
                waitForInput = new Thread();
                waitForInput.start();
                for (int x = 0; x < (currentTurn*100) && !waitForInput.isInterrupted() && !lose; x++)
                {
                    waitForInput.sleep(playerAllottedTime/100);
                }
                // Add a timeout while the sequence is being repeated to the user.
                while(repeatingSequence)
                {
                    Thread.sleep(1500);
                }
            }
            catch (InterruptedException e)
            {
                System.out.println("Wait Timer Interrupted. Going to Next turn");

                continue;
            }
        }

        // Game WON
        if (currentTurn == MaximumNumberOfTurns)
        {
            WinOrLoseGame(true);
        }else // Game LOST
        {
            WinOrLoseGame(false);
        }
    }

    // Sets the default game start parameters
    private void ResetGame()
    {
        lose = false;
        win = false;
        currentScore = 0;
        currentTurn = 0;
        UpdateMainHeader("simon");
        ReadHighScore();
        UpdateVisualScore();
        GenerateSequence();
    }

    // Updates the main text header in the center of the game
    public static void UpdateMainHeader(String instruction)
    {
        // Tells the player to watch the sequence
        if (Objects.equals(instruction, "watch"))
        {
            simonText.setFont(new Font("Verdana", Font.BOLD,75));
            simonText.setText("WATCH");
            simonText.setBounds(345,380,320,80);
            gamePane.repaint();

        } // Tells the player to repeat the sequence
        else if (Objects.equals(instruction, "repeat"))
        {
            simonText.setFont(new Font("Verdana", Font.BOLD,70));
            simonText.setText("REPEAT");
            simonText.setBounds(345,380,320,80);
            gamePane.repaint();

        } // Tells the player he won
        else if (Objects.equals(instruction, "you win"))
        {
            simonText.setFont(new Font("Verdana", Font.BOLD,60));
            simonText.setText("YOU WIN");
            simonText.setBounds(340,380,320,80);
            gamePane.repaint();

        } // Tells the player he lost
        else if (Objects.equals(instruction, "you lose"))
        {
            simonText.setFont(new Font("Verdana", Font.BOLD,55));
            simonText.setText("YOU LOSE");
            simonText.setBounds(335,380,320,80);
            gamePane.repaint();

        } // Classic "Simon" signature in the UI
        else if (Objects.equals(instruction, "simon"))
        {
            simonText.setFont(new Font("Verdana", Font.BOLD,80));
            simonText.setText("SIMON");
            simonText.setBounds(345,380,320,80);
            gamePane.repaint();
        } // New high score is displayed as in congratulation
        else if (Objects.equals(instruction, "new high"))
        {
            simonText.setFont(new Font("Verdana", Font.BOLD,25));
            simonText.setText("NEW HIGH SCORE: " + String.valueOf(currentScore));
            simonText.setBounds(345,380,320,80);
            gamePane.repaint();
        }
    }

    // Displays a visual countdown at the start of the game.
    public void StarCountdown()
    {
        // Prevents game defeat during countdown by accidental clicking
        sequenceMode = true;

        try
        {
            Thread.sleep(1500);
            simonText.setFont(new Font("Verdana", Font.BOLD,90));
            simonText.setBounds(465,380,320,80);
            simonText.setText("3");
            gamePane.repaint();

            Thread.sleep(1000);
            simonText.setText("2");
            gamePane.repaint();

            Thread.sleep(1000);
            simonText.setText("1");
            gamePane.repaint();

            Thread.sleep(1000);
            UpdateMainHeader("watch");
            gamePane.repaint();
        } catch(Exception e)
        {
            System.out.println("Countdown interrupted");
            e.printStackTrace();
        }
    }

    // Game is won: Updates UI to reflect win. Plays a victory sequence,
    // stores current score if it is equal or better than previous high score
    // for this difficulty. Closes the window after all that so that the
    // player can start a new game with the same or different difficulty.

    // Game is lost: Updates the UI, launches a defeat sequence
    // stores score if it is better or equal than the previous high score.
    // closes window and lets the user be able to start a new game with the same
    // or equal configuration.

    // wl = win; !wl = lose
    public void WinOrLoseGame(boolean wl)
    {
        buttonLastSequence.setVisible(false);
        gameFrame.getContentPane().repaint();
        if (wl)
        {
            WinSequence();
        } else
        {
            DefeatSequence();
        }
        GameInPlay = false;
        if (currentScore >= highScore && currentScore != 0)
        {
            UpdateMainHeader("new high");
            WriteNewHighScore();
        }
        try {
            Thread.sleep(3000);
        }catch (Exception e)
        {
            System.out.println("Ending Wait time Interrupted.");
            e.printStackTrace();
        }
        gameFrame.dispose();
    }


    // Plays all the signals according to the turn and difficulty pre-selected.
    public void PlaySequence(int interval) throws InterruptedException
    {
        System.out.println("NOW: Playing Sequence");
        UpdateMainHeader("watch");
        sequenceMode = true;

        int wait = 0; // Time to wait in milliseconds
        // Waiting a standard 700 milliseconds before starting the sequence.
        TimeUnit.MILLISECONDS.sleep(700);
        for (int i = 0; i < (currentTurn) && !win && !lose; i++)
        {
            // Play signals and intervals according to
            if (sequence.get(i) == 1) // Green
            {
                buttonGreen.doClick(650);
            } else if (sequence.get(i) == 2) // Yellow
            {
                buttonYellow.doClick(650);
            }else if (sequence.get(i) == 3) // Blue
            {
                buttonBlue.doClick(650);
            }else if (sequence.get(i) == 4) // Red
            {
                buttonRed.doClick(650);
            }

            // DYNAMIC WAIT TIME:
            // There is a dynamic wait time after each button from the sequence
            // unless the button is the last one in the sequence.
            if (i != (currentTurn - 1))
            {
                // Time between signals
                if (currentTurn < 5 ) // Before 5th turn
                {
                    wait = IntervalBetweenSignals[interval][0];
                } else if (currentTurn < 9) // Before 9th turn
                {
                    wait = IntervalBetweenSignals[interval][1];
                }else if (currentTurn < 13) // Before 13th turn
                {
                    wait = IntervalBetweenSignals[interval][2];
                }else // During and after 13th turn
                {
                    wait = IntervalBetweenSignals[interval][3];
                }
            } else // No wait
            {
                wait = 0;
            }

            TimeUnit.MILLISECONDS.sleep(wait);
        }
        UpdateMainHeader("repeat");
        sequenceMode = false;
    }

    // Creating a sequence of signals for each of the 15 turns.
    // Signals and their id
    // Green, 1
    // Yellow, 2
    // Blue, 3
    // Red, 4
    public void GenerateSequence()
    {
        System.out.println("\nNOW: Generating Random Game-long Sequence:");
        int signalID = 0;
        for (int i = 1; i < MaximumNumberOfTurns + 1; i++)
        {
            signalID = randomSequenceGenerator.nextInt(4) + 1;
            if (signalID == 1)
                System.out.println("Green");
            if (signalID == 2)
                System.out.println("Yellow");
            if (signalID == 3)
                System.out.println("Blue");
            if (signalID == 4)
                System.out.println("Red");

            sequence.add(signalID);
        }
    }

    //Plays audio file indicated by parameter
    public void playWavSoundFile(String soundFileName)
    {
        try
        {
            InputStream is= getClass().getResourceAsStream("/Sounds/" + soundFileName);
            AudioInputStream audioIS = AudioSystem.getAudioInputStream(new BufferedInputStream(is));
            Clip myClip = AudioSystem.getClip();
            myClip.open(audioIS);
            myClip.start();
        } catch (Exception e)
        {
            System.out.println("Error: Failed to play audio file");
            e.printStackTrace();
            System.exit(0);
        }
    }

    // Launches the sequence for defeat when the game is lost
    public void DefeatSequence()
    {
        System.out.println("NOW: Defeat Sequence");
        UpdateMainHeader("you lose");
        try
        {
            buttonGreen.setBackground(Color.WHITE);
            buttonYellow.setBackground(Color.WHITE);
            buttonBlue.setBackground(Color.WHITE);
            buttonRed.setBackground(Color.WHITE);
            gamePane.repaint();

            playWavSoundFile("defeat.wav");
            TimeUnit.MILLISECONDS.sleep(1000);

            buttonGreen.setBackground(Color.GREEN);
            buttonYellow.setBackground(Color.YELLOW);
            buttonBlue.setBackground(Color.BLUE);
            buttonRed.setBackground(Color.RED);
            gamePane.repaint();
        }catch (Exception e)
        {
            System.out.println("Defeat Sequence Interrupted");
            e.printStackTrace();
        }
    }

    // Launches the winning sequence. A celebration where buttons change
    // colors and a fun audio plays. This is for when the game is won.
    public void WinSequence()
    {
        System.out.println("NOW: Winning Sequence");
        UpdateMainHeader("you win");
        // Green yellow red blue
        try
        {
            playWavSoundFile("win.wav");

            // Green
            buttonGreen.setBackground(Color.RED);
            gamePane.repaint();
            TimeUnit.MILLISECONDS.sleep(200);

            // Yellow
            buttonYellow.setBackground(Color.BLUE);
            gamePane.repaint();
            TimeUnit.MILLISECONDS.sleep(200);

            // Blue
            buttonBlue.setBackground(Color.YELLOW);
            gamePane.repaint();
            TimeUnit.MILLISECONDS.sleep(200);

            // Red
            buttonRed.setBackground(Color.GREEN);
            gamePane.repaint();
            TimeUnit.MILLISECONDS.sleep(200);

            // All at the same time
            TimeUnit.MILLISECONDS.sleep(200);
            buttonGreen.setBackground(Color.BLACK);
            buttonYellow.setBackground(Color.BLACK);
            buttonBlue.setBackground(Color.BLACK);
            buttonRed.setBackground(Color.BLACK);
            gamePane.repaint();

            TimeUnit.MILLISECONDS.sleep(300);
            buttonGreen.setBackground(Color.WHITE);
            buttonYellow.setBackground(Color.WHITE);
            buttonBlue.setBackground(Color.WHITE);
            buttonRed.setBackground(Color.WHITE);
            gamePane.repaint();

            TimeUnit.MILLISECONDS.sleep(200);
            buttonGreen.setBackground(Color.GREEN);
            buttonYellow.setBackground(Color.YELLOW);
            buttonBlue.setBackground(Color.BLUE);
            buttonRed.setBackground(Color.RED);
            gamePane.repaint();
        }catch(Exception e)
        {
            System.out.println("Winning Sequence Interrupted");
            e.printStackTrace();
        }
    }

    // Repeats the last sequence at the same speed
    // If the player has more than 3 points then he/she will
    // lose 3 points for repeating the sequence.
    public void RepeatLastSequence()
    {
        if (!sequenceMode && GameInPlay) {
            try {
                repeatingSequence = true;
                if (currentScore > 3)
                {
                    currentScore -= 3;
                    UpdateVisualScore();
                }
                // Cancel current Game Over allotted time
                expectedDefeatTask.cancel(true);
                PlaySequence(gameInterval);
                // Restart Game Over allotted Time
                expectedDefeatTask = scheduler.schedule(defeat,
                        playerAllottedTime,
                        TimeUnit.MILLISECONDS);
                repeatingSequence = false;

            } catch (InterruptedException e) {
                System.out.println("Timer Interrupted.");
                e.printStackTrace();
                if (!win && !lose)
                {
                    lose = true;
                }
            }
        }
    }

    // Read High Score from file according to the difficulty of the game.
    // Each difficulty: easy, medium, hard has a different high score.
    // This loads the correct score and prints it to the UI.
    public void ReadHighScore()
    {
        Scanner myReader;
        File hsFile;
        System.out.println("NOW: Reading High Score");

        try{
            if (gameAllottedTime == 0)
            { //HighScore difficulty Easy
                hsFile = new File("High Score - Easy.txt");
            } else if (gameAllottedTime == 1)
            { //HighScore difficulty Medium
                hsFile = new File("High Score - Medium.txt");
            }  else
            {   //HighScore difficulty Hard
                hsFile = new File("High Score - Hard.txt");
            }

                if(hsFile.exists())
                {
                    myReader = new Scanner(hsFile);
                    highScore = myReader.nextInt();
                    highScorePlayer = myReader.nextLine();
                    UpdateVisualHighScore();

                }else
                {
                    System.out.println("Previous High Score File was not found." +
                            " A new one was created.");
                    if (!WriteNewHighScore())
                    {
                        System.out.println("Failed to create new high score text file");
                        System.exit(0);
                    }
                    ReadHighScore();
                    throw new FileNotFoundException();
                }

            if (gameAllottedTime == 0)
            System.out.println("NOW: High Score File Read: Difficulty: \"EASY\"");
            if (gameAllottedTime == 1)
            System.out.println("NOW: High Score File Read: Difficulty: \"MEDIUM\"");
            if (gameAllottedTime == 2)
            System.out.println("NOW: High Score File Read: Difficulty: \"HARD\"");

            System.out.println("HS: " + highScore + "\nHS Player: " + highScorePlayer);

            }catch(Exception e)
            {
            System.out.println("EXCEPTION: HighScore File Not Found. A new will be created if possible otherwise the game will shut");
            }
    }

    // Creates a text file to store the high score and player name
    // according to the difficulty of the current game. There are 3 levels of difficulty
    // therefore this will create the file according to the difficulty.
    public boolean WriteNewHighScore()
    {
        File newHS;
        String fileText = currentScore + " " + currentScorePlayer;
        // Path to this jar
        try
        {

        if (gameAllottedTime == 0)
        {//HighScore Difficulty Easy
            newHS = new File("High Score - Easy.txt");
            if (WriteNewFile(newHS,fileText))
            {
                System.out.println("High Score File Created: " + newHS.getName());
                return true;
            }

        }else if (gameAllottedTime == 1)
        {//HighScore Difficulty Medium
            newHS = new File("High Score - Medium.txt");
            if (WriteNewFile(newHS,fileText))
            {
                System.out.println("High Score File Created: " + newHS.getName());
                return true;
            }

        }else if (gameAllottedTime == 2)
        { //HighScore Difficulty
            newHS = new File("High Score - Hard.txt");
            if (WriteNewFile(newHS,fileText))
            {
                System.out.println("High Score File Created: " + newHS.getName());
                return true;
            }
        }
        } catch(Exception e)
        {
            System.out.println("Failed to write high score");
            e.printStackTrace();
        }
        // High Score file could not be created.
        return false;
    }

    // Creates a new high-score-text-file according to the current difficulty,
    //score, and name of the player.
    public boolean WriteNewFile(File newFile, String text)
    {
        try {
            FileWriter fileW = new FileWriter(newFile, false);
            fileW.write(text);
            fileW.close();
            return true;
        } catch (IOException e) {
            System.out.println("EXCEPTION: Failed to Create a New High Score File");
            e.printStackTrace();
            return false;
        }
    }

    // Updates the visual current score counter in the middle of the UI.
    public void UpdateVisualScore()
    {
        scoreText.setText(String.valueOf(currentScore));
    }

    // Updates the high score located at the top left of the UI.
    public void UpdateVisualHighScore()
    {
        highscoreText.setText("<html>HIGH SCORE:<br>" + highScorePlayer + ":  "
            + String.valueOf(highScore)+"</html>");
    }
}