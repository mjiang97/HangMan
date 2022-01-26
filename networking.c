#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>

int server_setup() {
  struct addrinfo * hints, * results;
  hints = calloc(1,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; //TCP socket
  hints->ai_flags = AI_PASSIVE; //only needed on server
  getaddrinfo(NULL, "9845", hints, &results);  //Server sets node to NULL

  //create socket
  int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

  bind(sd, results->ai_addr, results->ai_addrlen);
  printf("Listening");
  listen(sd, 10);

  free(hints);
  freeaddrinfo(results);

  return sd;
}


int server_connect(int sd) {
  int client_socket;
  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);
  client_socket = accept(sd,(struct sockaddr *)&client_address, &sock_size);
  return client_socket;
}


int client_connect(char * ip){
  if(strlen(ip) < 2){
    strcpy(ip, "127.0.0.1");
    printf("Using localhost\n");
  }
  struct addrinfo * hints, * results;
  hints = calloc(1,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; //TCP socket
  hints->ai_flags = AI_PASSIVE; //only needed on server
  getaddrinfo(ip, "9845", hints, &results);  //Server sets node to NULL

  //create socket
  int sd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

  connect(sd, results->ai_addr, results->ai_addrlen);

  free(hints);
  freeaddrinfo(results);

  return sd;
}
