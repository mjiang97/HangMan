#include "client.h"
#include "networking.h"

int sd;

static void sighandler(int signo) {
  if ( signo == SIGINT ){
    printf("\n");
    close(sd);
    exit(0);
  }
}


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


  char ip[200];
  printf("\033[0;36mEnter IP address of server (empty for localhost):\033[0m ");
	fgets(ip, sizeof(ip), stdin);
  // printf("IP%sIP\n", ip);
  int n;
  for(n=0; n<strlen(ip); n++){
    if(ip[n] == '\n')
      ip[n] = '\0';
  }
  sd = client_connect(ip);

  signal(SIGINT, sighandler);

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
      printf("\n\033[0;36mEnter your one letter guess:\033[0;33m ");
      fgets(input, 100, stdin);
      printf("\033[0m");
      if(strlen(input) != 2){
        printf("\033[0;36mPlease enter one (1) letter\n");
        continue;
      }
      if((input[0] < 'A' || input[0] > 'Z') && (input[0] < 'a' || input[0] > 'z')){
        printf("\033[0;36mPlease enter a letter\n");
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


    if(!strcmp(from_server + strlen(from_server) - 10, "Game Over\n")){
	     close(sd);
       exit(0);
    }

  }


  return 0;
}
