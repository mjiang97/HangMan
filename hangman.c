#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ncurses.h>
#include <signal.h>

#define TOTALNOUNS 985

#include "hangmen.h"
#include "networking.h"

void playGame(char* noun, int client){
  // Setup
  int failedAttempts = 0;

  int ansLength = strlen(noun);
  char guess[ansLength+1];
  int i;
  for(i=0; i<ansLength; i++){ guess[i] = '_'; }
  guess[ansLength] = '\0';
  char to_client[10000];

  // Actual Game
  strcpy(to_client, "\n\033[1;36mWELCOME TO HANGMAN :D\033[0;35m\n\nEnter your guesses below.\nPress CTRL+C to quit.\033[0m\n");
  if(write(client, to_client, 10000) == -1){
    printf("Error: %s", strerror(errno));
  }

  // Server prints answer
  printf("\n\nGame started. Answer: ");
  for(i=0; i<ansLength; i++){ printf("%c ", noun[i]); }
  printf("\n");


  while(1){
    to_client[0] = '\0';
    // the hangman so far
    strcat(to_client, "\n");
    strcat(to_client, levelOneHM[failedAttempts]);
    strcat(to_client, "\n\n");

    //  the guess so far
    char tmp[ansLength*2];
    for(i=0; i<=ansLength*2; i+=2){
      tmp[i] = guess[i/2];
      tmp[i+1] = ' ';
    }
    strcat(to_client, tmp);
    // printf("tmp: %stmp\n", tmp);
    // printf("tmplen2: %lu\n", strlen(tmp));

    if(write(client, to_client, strlen(to_client)) == -1){
      printf("Error: %s", strerror(errno));
    }
    //printf("TOCLIENT%sTOCLIENT\n", to_client);

    // letter guess from client
    char userLetter;
    if(read(client, to_client, 100) == -1){
      printf("Error: %s", strerror(errno));
    }
    userLetter = to_client[0];
    printf("letter guess: %c\n", userLetter);
    to_client[0] = '\0';

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
      strcpy(to_client, "\n\nYou win! Thanks for playing :)\nGame Over\n");
      if(write(client, to_client, 10000) == -1){
        printf("Error: %s", strerror(errno));
      }
      exit(0);
    }

    else if(!isCorrect){
      failedAttempts++;
      if(failedAttempts >= 6){
        to_client[0] = '\0';
        strcat(to_client, "\n\n\n\n\n");
        strcat(to_client, levelOneHM[failedAttempts]);
        strcat(to_client, "\n\nYou lost! The answer was ");
        strcat(to_client, noun);
        strcat(to_client, ". Better luck next time...\nGame Over\n");
        if(write(client, to_client, 10000) == -1){
          printf("Error: %s", strerror(errno));
        }
        exit(0);
      }
      strcpy(to_client, "\n\n\n\n\n\033[1;31mIncorrect! Try again\033[0m\n");
      if(write(client, to_client, 10000) == -1){
        printf("Error: %s", strerror(errno));
      }
    }


    else{
      strcpy(to_client, "\n\n\n\n\n\033[1;32mCorrect!\033[0m\n");
      if(write(client, to_client, 10000) == -1){
        printf("Error: %s", strerror(errno));
      }
    }
    printf("failed: %d\n", failedAttempts);
    printf("guess so far: %s\n", guess);
  }
}




char* generate(){
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
  srand(time(NULL));
  int x = rand()%TOTALNOUNS;
  char * noun = nounsArr[x];
  return noun;
}



int main(){

  // initscr();			/* Start curses mode 		  */
	// printw("Hello World !!!!!");	/* Print Hello World		  */
	// refresh();			/* Print it on to the real screen */
	// getch();			/* Wait for user input */
	// endwin();			/* End curses mode		  */

  int client;
  int sd = server_setup();


  while(1){
    client = server_connect(sd);
    int f = fork();
    if(f == 0){
      playGame(generate(), client);
    }

  }
  endwin();			/* End curses mode		  */
  return 0;
}
