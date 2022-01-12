# HangMan
By: **H**ebe Huang and **M**acy Jiang pd 4

## Project Description:
HangMan is a collaborative multiplayer word-guessing game. Work with other players to guess one letter at a time and try to beat the game before the man gets hanged! 

## User Interface:
### MAIN MENU
Our program will create a terminal-independent interface using ncurses that will allow user(s) to choose out of several difficulty levels on the main menu and view the leaderboard. 

### LEVELS
The interface will display the number of players (plus a list of all the players’ names, color-coded) and the difficulty level, which will be indicated by the icons shown on the interface. The more features the icon has, the more tries the players have to guess.
	
### THE GAME
Word(s) will be generated onto the interface from a randomized library. Player(s) will each take one turn to guess a letter, in a collaborative effort to guess the entire word as a team. A box on part of the interface will be dedicated to storing the incorrect letters (color-coded to show which player guessed the letter) that were guessed. 

### THE LEADERBOARD
A leaderboard will display the number of correct guesses by each player after the game ends. 

## Technical Design:
### TOPICS COVERED
- **Working with files**: writing leaderboard info
- **Finding information about files**: getting leaderboard info and info from any other files we have
- **Processes**: forking for each game and for each player
- **Shared Memory**: for progress in the game (hangman, letters unlocked, incorrect letters found)
- **Sockets**: for communicating between the server and clients

## Work Distribution:

## Timeline:
- 1/13-1/15: 
	- Work on HangMan for single player
	- Get HangMan to work for multiple players 
- 1/16-1/18:
	- Set up UI
- 1/19-1/21:
	- Adding the leaderboard
- With remaining time: 
	- Add more options for difficulty, colors
