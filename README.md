# HangMan
By: **H**ebe Huang and **M**acy Jiang pd 4

## Project Description:
HangMan is a collaborative multiplayer word-guessing game. Work with other players to guess one letter at a time and try to beat the game before the man gets hanged! 

## User Interface:
### MAIN MENU
Our program will create a terminal-independent interface using ncurses that will allow user(s) to choose out of several difficulty levels on the main menu and view the leaderboard. 

### LEVELS
The interface will display the number of players that joined (plus a list of all the players’ names, color-coded) and the difficulty level, which will be indicated by the hangman shown on the interface. The more features the hangman has, the more tries the players have to guess.
	
### THE GAME
Word(s) will be generated onto the interface from a randomized library. Player(s) will each take one turn to guess a letter, in a collaborative effort to guess the entire word as a team. A box on part of the interface will be dedicated to storing the incorrect letters (color-coded to show which player guessed the letter) that were guessed. 

### THE LEADERBOARD
A leaderboard will display the number of correct guesses by each player after the game ends. 

## Technical Design:
### TOPICS COVERED
- **Working with files**: Writing leaderboard info
- **Finding information about files**: Getting leaderboard info and info from any other files we have
- **Processes**: Forking for each game and for each player
- **Shared Memory**: For progress in the game (hangman, letters unlocked, incorrect letters found)
- **Sockets**: For communicating between the server and clients

### Data structures / Algorithms:
- Ncurses
	- On debian: sudo apt install libncurses5-dev libncursesw5-dev
	- On other systems google: "install ncurses (platform)" and follow instructions that look somewhat trustworthy 


### Work Distribution:
- Basic guessing system (Hebe, Macy)
- Create a switch that includes Ascii art for each step of the hangman’s formation (Macy)
- Generating random sentences for players to guess using random adjectives, nouns, and verbs that are read in from different files (Hebe)
- Updating and getting info from the leaderboards file (Macy, Hebe)
- Making the game run with multiple players (Hebe, Macy) 

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
