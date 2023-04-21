Instructions:
1. Execute the SimonGame.jar file.
2. On the Setup Window: Enter Your Desired Player Name
3. Select the Desired Levels of Difficulty
4. Start Game
5. Play the game, it's simple:
	A. Wait for countdown to end
	B. Watch the sequence of signals(lights)
	C. Click on the buttons(signals) to repeat the exact sequence shown before by the game.
	
	Losing: Failure to repeat the exact sequence by pressing the wrong button or by failing to press any button and running out of the allotted time.
	
	Winning: Repeating the exact sequence for 15 turns
	
	Highscore: When the game ends due to a win or lose if the current score is higher or equal than the previous highs score then a new high score will be saved and replace the previous one. Notice that if the previous high score is the maximum amount of points and the new high score is the same then the previous one will be replaced.
	
Details about the settings:

Allotted Time: (reaction time a player has to press a button)
Easy   -> The player has 4000ms to press a button
Medium -> The player has 3000ms to press a button
Hard   -> The player has 2000ms to press a button

Interval: (time between game signals)
Easy:
Before 5th turn         -> The game waits 1500ms between signals.
From   6th to 8th turn  -> The game waits 1300ms between signals.
From   9th to 12th turn -> The game waits 1100ms between signals.
From  13th to 15th turn -> The game waits  900ms between signals.

Medium:
Before 5th turn         -> The game waits 1100ms between signals.
From   6th to 8th turn  -> The game waits 1000ms between signals.
From   9th to 12th turn -> The game waits  900ms between signals.
From  13th to 15th turn -> The game waits  800ms between signals.

Hard:
Before 5th turn         -> The game waits 900ms between signals.
From   6th to 8th turn  -> The game waits 700ms between signals.
From   9th to 12th turn -> The game waits 500ms between signals.
From  13th to 15th turn -> The game waits 400ms between signals.


Variations:
-This game exclusively has a single player mode which is the best known and the most fun mode to play with.

-The original game does have the automatic changes changes in interval after a few turns as mentioned above. On the other hand, I set the times in ms based on an educated guess and personal preference. I could not find the real time intervals from the physical game.

Variation and Extra:
-I implemented and modified the REPEAT button, pressing this button adds more time to the player to make a move and plays the sequence back. If the player has more than 3 points then the player will lose 3 points for using the button. This way the player will think twice about repeating the last sequence. The button. The button will hide when the game is won or lost by design. Spamming or abusing the button will make the player lose the game.

Extra:
-There are 3 high scores. The high scores are independent from each other and solely based on the Allotted Time difficulty and NOT on the Interval. In other words, if the conditions for a new high score occur, selecting Allotted Time "Easy" will make the new high score be saved for the "Easy" difficulty and so on for  medium and hard difficulties.

Extra:
-Interval and Allotted Time settings as previously explained. (And the combination of both)

About Partners:
Not Applicable. This game was fully written and developed solely by Claudio Osorio.
