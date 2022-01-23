all: hangman.o hangmen.o 
	gcc -o hangman hangman.o hangmen.o -lncurses


hangman.o: hangman.c hangmen.h
	gcc -c hangman.c

hangmen.o: hangmen.c hangmen.h
	gcc -c hangmen.c

run:
	./hangman

clean:
	rm *.o
	rm hangman