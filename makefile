all: hangman.o
	gcc -o hangman hangman.o -lncurses

hangman.o:
	gcc -c hangman.c

run:
	./hangman
