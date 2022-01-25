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

#include "client.h"
#include "networking.h"

#define TOTALNOUNS 985


int main(){


  // initscr();			/* Start curses mode 		  */
  // cbreak();
  // noecho();
  // start_color();
  // init_pair(1, COLOR_BLACK, COLOR_BLACK);
  // mvaddstr(10, 10, "_|    _|    _|_|    _|      _|    _|_|_|  _|      _|    _|_|    _|      _|");
  // mvaddstr(11, 10, "_|    _|  _|    _|  _|_|    _|  _|        _|_|  _|_|  _|    _|  _|_|    _|");
  // mvaddstr(12, 10, "_|_|_|_|  _|_|_|_|  _|  _|  _|  _|  _|_|  _|  _|  _|  _|_|_|_|  _|  _|  _|");
  // mvaddstr(13, 10, "_|    _|  _|    _|  _|    _|_|  _|    _|  _|      _|  _|    _|  _|    _|_|");
  // mvaddstr(14, 10, "_|    _|  _|    _|  _|      _|    _|_|_|  _|      _|  _|    _|  _|      _|");
  // mvaddstr(16, 35, "press any key to start");
  // refresh();
  // keypad(stdscr, TRUE);




  int sd = client_connect();

  char input[100];
  char from_server[10000];

  // Welcome message
  if(read(sd, from_server, sizeof(from_server)) == -1){
    printf("Error: %s", strerror(errno));
  }
  printf("%s\n", from_server);

  while(1){
    if(read(sd, from_server, sizeof(from_server)) == -1){
      printf("Error: %s", strerror(errno));
    }
    
    printf("%s\n", from_server);
    char userLetter = '_';
    while (userLetter == '_') {
      printf("\nEnter your one letter guess: ");
      fgets(input, 100, stdin);
      if(strlen(input) != 2){
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

    if(write(sd, input, sizeof(input)) == -1){
      printf("Error: %s", strerror(errno));
    }

    if(read(sd, from_server, sizeof(from_server)) == -1){
      printf("Error: %s", strerror(errno));
    }
    printf("%s\n", from_server);

    char tmp[10];
    strncpy(tmp, from_server + strlen(from_server) - 10, sizeof(tmp));
    printf("%s\n", tmp);
    if(!strcmp(tmp, "Game over\n")){
	exit(0);
    }

  }


  return 0;
}
