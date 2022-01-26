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
#include <signal.h>
#include <ncurses.h>

#define TOTALNOUNS 985

int sd;

static void sighandler(int signo);
