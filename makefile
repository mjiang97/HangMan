all: client server


client: client.o networking.o
	gcc -o client client.o networking.o -lncurses

server: hangman.o hangmen.o networking.o
	gcc -o server hangman.o hangmen.o networking.o -lncurses


hangman.o: hangman.c hangmen.h networking.h
	gcc -c hangman.c

hangmen.o: hangmen.c hangmen.h
	gcc -c hangmen.c

networking.o: networking.c networking.h
	gcc -c networking.c

client.o: client.c client.h
	gcc -c client.c

run:
	./hangman

clean:
	rm *.o
	rm server
	rm client