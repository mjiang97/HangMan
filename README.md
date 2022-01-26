# HangMan
By: **H**ebe Huang and **M**acy Jiang pd 4

## Project Description:
HangMan is a collaborative multiplayer word-guessing game. Work with other players to guess one letter at a time and try to beat the game before the man gets hanged! 

## Required Libraries:
- ncurses
	- On debian: `sudo apt install libncurses5-dev libncursesw5-dev`
	- On other systems google: "install ncurses (platform)" and follow instructions on reliable sites
	- Or use: `brew install ncurses`

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
