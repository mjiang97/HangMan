#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>

#define TOTALNOUNS 985

#include "hangmen.h"

int main(){

  // initscr();			/* Start curses mode 		  */
	// printw("Hello World !!!!!");	/* Print Hello World		  */
	// refresh();			/* Print it on to the real screen */
	// getch();			/* Wait for user input */
	// endwin();			/* End curses mode		  */


  // Gets a noun from common nouns list
  int in = open("nouns.csv", O_RDONLY);

  struct stat st;
  stat("nouns.csv", &st);
  int size = st.st_size;
  char buff[size];
  read(in, &buff, size);

  char nounsArr[TOTALNOUNS+1][100];
  int nounInd = 0;
  int i=0;
  for(i=0; i<size+1; i++){
    int li = 0;
    while(buff[i] != '\n' && i<size+1){
        nounsArr[nounInd][li] = buff[i];
        i++;
        li++;
    }
    int n;
    for(n=0; n<strlen(nounsArr[nounInd]); n++){
      if(nounsArr[nounInd][n] == ','){
        nounsArr[nounInd][n] = '\0';
      }
    }
    nounInd++;
  }



  // Setup 
  int failedAttempts = 0;

  srand(time(NULL));
  int x = rand()%TOTALNOUNS;
  char * noun = nounsArr[x];
  int ansLength = strlen(noun);
  char guess[ansLength+1];
  for(i=0; i<ansLength; i++){ guess[i] = '_'; }
  guess[ansLength] = '\0';




  // Actual Game
  printf("\nWELCOME TO HANGMAN :D\n");
  for(i=0; i<ansLength; i++){ printf("%c ", noun[i]); }
  printf("\n");
  printf("\n");
  
  char input[100];

  while(1){
    //Print the hangman so far
    printf("\n\n\n\n\n%s\n\n", levelOneHM[failedAttempts]);
    // Print the guess so far
    for(i=0; i<ansLength; i++){ printf("%c ", guess[i]); }
    printf("\n");

    char userLetter = '_';
    // Get input, check if valid
    while(userLetter == '_'){
      printf("Enter your one letter guess: ");
      fgets(input, 100, stdin);
      if(strlen(input) > 2){
        printf("Please enter one (1) letter\n");
        continue;
      }
      if((input[0] < 'A' || input[0] > 'Z') && (input[0] < 'a' || input[0] > 'z')){
        printf("Please enter a letter\n");
        continue;
      }
      userLetter = input[0];
      if(userLetter > 'A' && userLetter < 'Z'){
        userLetter += 32;
      }

    }
    
    // Fill in letter if correct
    int isCorrect = 0;
    for(i=0; i<ansLength; i++){
      if(noun[i] == userLetter){
        guess[i] = userLetter;
        isCorrect = 1;
      }
    }

    // Check if there are letters left to guess
    int didyouwin = 1;
    for(i=0; i<ansLength; i++){
      if(guess[i] == '_'){
        didyouwin = 0;
        break;
      }
    }

    // If all letters are filled in, user wins
    if(didyouwin){
      printf("You win! Thanks for playing :)\n");
      break;
    }

    if(!isCorrect){
      failedAttempts++;
      if(failedAttempts >= 6){
        printf("\n\n\n\n\n%s\n\n", levelOneHM[failedAttempts]);
        printf("You lost! Better luck next time...\n");
        break;
      }
    }


  }

  return 0;
}
