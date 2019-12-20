all: programm

programm: main.o Funcs.o inputText.o
	gcc main.o	Funcs.o inputText.o -o programm

main.o: main.c Funcs.o inputText.o
	gcc -c main.c -o main.o

inputText.o: inputText.c
	gcc -c inputText.c -o inputText.o

Funcs.o: Funcs.c
	gcc -c Funcs.c -o Funcs.o

clean:
	rm -rf *.o programm
