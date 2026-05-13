# BattleArena

## FlowChart

### Start Screen
The user is presented with three options (buttons):
1. Start a new game
2. Continue an unfinished game (ADDITIONAL FEATURE)
3. Exit

### Difficulty Levels
The user can choose from three difficulty levels:
1. Easy (One enemy)
2. Medium (Two enemies)
3. Hard (Three enemies)

### Character
After the user chooses a difficulty level, three characters are presented to choose from (Warrior - Archer - Mage):
1. User: Chooses a characater
2. Computer: Chooses characters randomly

### Game
Only one round is played.

Movement and Attack:
1. User can move their character by pressing the 4 arrows
2. User can turn 90 degrees in a clockwise direction by pressing 'r'
3. User can use normal attack by either shooting projectiles (Archer and Mage) or close-range attack (Warrior) by pressing space
4. User can use special attack by pressing 's' but 20 seconds must have passed since last special attack
5. When turning, the direction of attack changes.

Round Logic:
1. Each character is free to move and attack at all times.
2. If a character is successful in attacking another character (projectile collides) the attacking character's score increases:
    - Normal attack: By one point
    - Special attack: By three points
3. Computer chooses movements and attack randomly OR using AI component (ADDITIONAL FEATURE)
4. Game continues until timer is up or user exits the game through the settings menu
5. If the user exits the game before timer is up, they are asked whether they want to save the progress or not:
    - NO: the user exits immediately
    - YES: the time and scores are saved in a file

### Game Exit
1. A window is shown with "Game Over"
2. A window is shown with the scores for each player





