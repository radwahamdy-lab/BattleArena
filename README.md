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
### Data Members
1. Score / Health
2. Direction (struct)
3. Position (struct)
4. Initial Health 
5. Base Damage
### Functions
1. move(Position newPos)
2. attack() -> virtual
3. turn() -> clockwise/anti (degree=90)
4. takeDamage(int dmg)
5. getHealth()
6. getPos()
7. getDirection()
8. getScore()
10. displayHealth()

## Warrior
### Data Members
1. Damage
2. Health
### Functions
1. attack() -> special case

## Archer
### Data Members
1. Damage
2. Health
### Functions
1. attack()

## Mage
### Data Members
1. Damage
2. Health
### Functions
1. attack()

## Projectile
### Data Members
1. speed
2. position
3. damage value
4. color
5. size
### Functions
1. isCollide()

## Game Class
### Data Members
1. const characters=2
2. timer=2 minutes
3. game_state=paused/running/not running
4. Game Menu
5. field_color
### Functions
1. displayScore()
2. displayWinner()

## Game Menu
### Data Members
### Functions
1. restart()
2. pause()
3. exit()

