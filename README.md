# BattleArena

## Start Screen:

1. Player chooses a character from the three characters: 
	- Warrior
	- Archer
	- Mage
2. Computer randomly chooses a character
	  - Difficult Levels (**OPTIONAL**)
		- Easy: Computer chooses one character
	    - Medium: Computer chooses two characters
	    - Hard: Computer chooses three characters


***

## Game Logic:

1. Choose randomly who should start
2. Both the computer and the player have two types of attacks: normal attack, special attack
3. Loop until time is up or a player's health becomes zero:
	- Player moves character using keyboard (make it move only up and down so it's easier)
	- Player presses a button to use their normal attack. 
	- Player presses another button to use a special attack
	- Special attack needs time to restore.
	- If the player's attack collides with the opponent
		- Opponent: health goes down
		- Player: score goes up
	- All of this is the same with the computer:
		- Randomly OR Add AI component (**OPTIONAL**)

***

## Exiting Logic:

1. If game is finished:
	1. Show "Game Over"
	2. Show a window with the two players' scores and the winner
2. If game isn't finished (**OPTIONAL**):
   Ask user whether to save the game or not

### Game File Format:

1. Score for each player
2. Health for each player
3. Time remaining until round is over

***

## Additional Notes:  

  1. Interrupting actions
     - Player presses space: pause the game and open the settings menu
  2. Settings Menu Format:
     1. Restart Button
     2. Exit Button

***

# Classes:
## Character (Abstract)
## Warrior
## Archer
## Mage

![[assets/Battle-Arena-UML.jpg]]
