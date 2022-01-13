all: hangman.o
	gcc -o hangman hangman.o -lncurses

hangman.o: hangman.c
	gcc -c hangman.c

run:
	./hangman
