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

#define TOTALNOUNS 996
int main(){

  // initscr();			/* Start curses mode 		  */
	// printw("Hello World !!!!!");	/* Print Hello World		  */
	// refresh();			/* Print it on to the real screen */
	// getch();			/* Wait for user input */
	// endwin();			/* End curses mode		  */

  int in = open("nouns.csv", O_RDONLY);

  struct stat st;
  stat("nouns.csv", &st);
  int size = st.st_size;
  char buff[size];
  read(in, &buff, size);

  char nounsArr[TOTALNOUNS+1][100];
  int nounInd = 0;
  int i=0;
  for(i=i+1; i<size+1; i++){
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
  for(i=0; i<TOTALNOUNS; i++){
    printf("%d: %s\n", i, nounsArr[i]);
  }



  return 0;
}
