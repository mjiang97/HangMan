# HangMan
By: **H**ebe Huang and **M**acy Jiang pd 4

## Project Description:
HangMan is a collaborative multiplayer word-guessing game. Work with other players to guess one letter at a time and try to beat the game before the man gets hanged! 

## How to Run the Game:
- Clone this repository
`git clone https://github.com/mjiang97/HangMan`
- Change directories
`cd HangMan`
- Use make to compile
`make`
- Open two or more terminal windows and run the server and client(s)
using `./server` and `./client`
- press ctrl-c to exit the server or client

## Known Bugs
- During some turns the hangman and/or the word progress will not show up
- During some turns there will be extra characters or underscores after the word progress
- We tried to implement ncurses but did not get it to work

## Features that could be implemented in the future
- Getting the game to work for multiple players for the same game/word
- Setting up a leaderboard
- Include the alphabet and show which letters have been guessed and were incorrect/correct

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
