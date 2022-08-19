// SIMON GAME
// Fully written by Claudio Osorio
// April 4th, 2022

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.util.Objects;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import static java.awt.Font.PLAIN;

public class SetupWindow extends JFrame
{
    private static final int ProgramFrameWidth = 400;
    private static final int ProgramFrameHeight = 500;

    static int gameAllottedTime = 0;        // Time allotted for player to move in milliseconds
    static int gameInterval = 0;            // Time interval between signals in milliseconds

    static String currentPlayerName = "Player1";

    // Thread manipulation for asynchronous gameplay.
    // Without this the user would not be able to interact with the execution
    // of the game-window frame gameplay.
    static ScheduledExecutorService scheduler = Executors.newSingleThreadScheduledExecutor();
    static Future<?> launchGame;
    Runnable gameInstance = new Runnable() {
        @Override
        public void run() {
            CreateGame();
        }
    };

    // Setup Window - Constructor
    public SetupWindow()
    {
        super("Simon - Game Setup");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE );
        this.setSize(ProgramFrameWidth, ProgramFrameHeight );
        this.setVisible(true);
        this.setFocusable(true);
        this.setResizable(false);
    }

    // Main Program Logic:
    // Creates game setup window and all the preparations to execute
    // a custom match.
    public static void main(String[] args)
    {
         SetupWindow setupWindow = new SetupWindow();
        JPanel setupPanel = new JPanel();
        setupPanel.setBounds(0,0,ProgramFrameWidth,ProgramFrameHeight);
        setupPanel.setVisible(true);
        setupPanel.setFocusable(true);
        setupPanel.setBackground(Color.BLACK);
        setupPanel.setForeground(Color.BLACK);

        // Setting Game window Icon
        BufferedImage iconImg;
        try {
            iconImg = ImageIO.read(Objects.requireNonNull(SetupWindow.class.getResource("/Data/Images/icon.png")));
            setupWindow.setIconImage(iconImg);
        }catch (Exception e)
        {
            System.out.println("Failed to load setup window icon image.");
            e.printStackTrace();
        }

        // Start Game Button
        JButton buttonStartGame = new JButton("Start Game");
        buttonStartGame.setBounds(20,25,340,100);
        buttonStartGame.setFont(new Font("Verdana", Font.PLAIN,40));
        buttonStartGame.setForeground(Color.WHITE);
        buttonStartGame.setBackground(Color.BLUE);
        buttonStartGame.setVisible(true);
        buttonStartGame.setFocusable(true);

        // Set Player Name
        JButton buttonEnterPlayerName = new JButton("Player Name");
        buttonEnterPlayerName.setBounds(125,150,140,60);
        buttonEnterPlayerName.setFont(new Font(Font.DIALOG, PLAIN, 18));
        buttonEnterPlayerName.setBackground(Color.WHITE);
        buttonEnterPlayerName.setForeground(Color.BLACK);
        buttonEnterPlayerName.setVisible(true);
        buttonEnterPlayerName.setFocusable(true);


        // Interval Selection Buttons
        final JLabel textInterval = new JLabel("Interval");
        textInterval.setBounds(150,240,100,20);
        textInterval.setFont(new Font(Font.DIALOG, Font.PLAIN, 25));
        textInterval.setForeground(Color.WHITE);
        textInterval.setBackground(Color.BLACK);

        //  Index 0
        JRadioButton buttonIntervalA = new JRadioButton("Easy");
        buttonIntervalA.setBounds(40,280,100,20);
        buttonIntervalA.setFont(new Font(Font.DIALOG, Font.PLAIN, 20));
        buttonIntervalA.setSelected(true);
        buttonIntervalA.setBackground(Color.BLACK);
        buttonIntervalA.setForeground(Color.WHITE);

        // Index 1
        JRadioButton buttonIntervalB = new JRadioButton("Medium");
        buttonIntervalB.setBounds(150,280,100,20);
        buttonIntervalB.setFont(new Font(Font.DIALOG, Font.PLAIN, 20));
        buttonIntervalB.setBackground(Color.BLACK);
        buttonIntervalB.setForeground(Color.WHITE);

        // Index 2
        JRadioButton buttonIntervalC = new JRadioButton("Hard");
        buttonIntervalC.setBounds(270,280,100,20);
        buttonIntervalC.setFont(new Font(Font.DIALOG, Font.PLAIN, 20));
        buttonIntervalC.setBackground(Color.BLACK);
        buttonIntervalC.setForeground(Color.WHITE);

        // Allotted Time Selection Buttons
        final JLabel textAllottedTime = new JLabel("Allotted Time");
        textAllottedTime.setBounds(110,350,200,20);
        textAllottedTime.setFont(new Font(Font.DIALOG, Font.PLAIN, 25));
        textAllottedTime.setForeground(Color.WHITE);
        textAllottedTime.setBackground(Color.BLACK);

        // Index 0
        JRadioButton buttonAllottedTimeA = new JRadioButton("Easy");
        buttonAllottedTimeA.setBounds(40,400,100,20);
        buttonAllottedTimeA.setFont(new Font(Font.DIALOG, Font.PLAIN, 20));
        buttonAllottedTimeA.setSelected(true);
        buttonAllottedTimeA.setBackground(Color.BLACK);
        buttonAllottedTimeA.setForeground(Color.WHITE);

        // Index 1
        JRadioButton buttonAllottedTimeB = new JRadioButton("Medium");
        buttonAllottedTimeB.setBounds(150,400,100,20);
        buttonAllottedTimeB.setFont(new Font(Font.DIALOG, Font.PLAIN, 20));
        buttonAllottedTimeB.setBackground(Color.BLACK);
        buttonAllottedTimeB.setForeground(Color.WHITE);

        // Index 2
        JRadioButton buttonAllottedTimeC = new JRadioButton("Hard");
        buttonAllottedTimeC.setBounds(270,400,100,20);
        buttonAllottedTimeC.setFont(new Font(Font.DIALOG, Font.PLAIN, 20));
        buttonAllottedTimeC.setBackground(Color.BLACK);
        buttonAllottedTimeC.setForeground(Color.WHITE);

        // Group Buttons
        ButtonGroup groupIntervals = new ButtonGroup();
        groupIntervals.add(buttonIntervalA);
        groupIntervals.add(buttonIntervalB);
        groupIntervals.add(buttonIntervalC);

        ButtonGroup groupAllottedTime = new ButtonGroup();
        groupAllottedTime.add(buttonAllottedTimeA);
        groupAllottedTime.add(buttonAllottedTimeB);
        groupAllottedTime.add(buttonAllottedTimeC);

        // Add all buttons and labels to the settings panel
        setupPanel.add(buttonStartGame);
        setupPanel.add(buttonEnterPlayerName);
        setupPanel.add(textAllottedTime);
        setupPanel.add(buttonAllottedTimeA);
        setupPanel.add(buttonAllottedTimeB);
        setupPanel.add(buttonAllottedTimeC);
        setupPanel.add(textInterval);
        setupPanel.add(buttonIntervalA);
        setupPanel.add(buttonIntervalB);
        setupPanel.add(buttonIntervalC);

        // Add Panel To Window
        setupWindow.add(setupPanel);

        // Setup buttons to their respective active configurations

        // Start Game button creates a new game instance on a separate thread.
        buttonStartGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                launchGame = scheduler.schedule(setupWindow.gameInstance,
                        0,
                        TimeUnit.MILLISECONDS);
            }
        });

        // Creates a new window for the player to enter his/her name
        buttonEnterPlayerName.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String result = (String)JOptionPane.showInputDialog(
                        setupWindow,
                        "Player Name:",
                        "Enter Player Name",
                        JOptionPane.PLAIN_MESSAGE,
                        null,
                        null,
                        currentPlayerName
                );
                if(result != null && result.length() > 0 && result.length() < 15){
                    currentPlayerName = result;

                }
            }
        });

        // Setting up the game difficulty according to the options selected
        buttonIntervalA.addActionListener(e -> gameInterval = 0);
        buttonIntervalB.addActionListener(e -> gameInterval = 1);
        buttonIntervalC.addActionListener(e -> gameInterval = 2);

        buttonAllottedTimeA.addActionListener(e -> gameAllottedTime = 0);
        buttonAllottedTimeB.addActionListener(e -> gameAllottedTime = 1);
        buttonAllottedTimeC.addActionListener(e -> gameAllottedTime = 2);

        // Updating the frame to reflect all the changes
        setupWindow.getContentPane().repaint();
    }

    // Creates instance of the game inside its own panel and then
    // adds it to the main program window
    public static void CreateGame()
    {
        JFrame gameWindow = new JFrame("Simon Game - " + currentPlayerName +" try to keep up with Simon!");
        gameWindow.setLayout(null);
        gameWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        gameWindow.setSize(1000, 1000 );
        gameWindow.setVisible(true);
        gameWindow.setFocusable(true);
        gameWindow.setResizable(false);

        // Setting Game window Icon
        BufferedImage iconImg;
        try {
            iconImg = ImageIO.read(Objects.requireNonNull(SetupWindow.class.getResource("/Data/Images/icon.png")));
            gameWindow.setIconImage(iconImg);
        }catch (IOException e)
        {
            System.out.println("Game Window Icon Could Not Be Found");
            e.printStackTrace();
        }

        // Launches the game with the selected configuration.
        SimonGame Game = new SimonGame(gameWindow, gameInterval, gameAllottedTime, currentPlayerName);
        Game.StartGame();

    }

}
