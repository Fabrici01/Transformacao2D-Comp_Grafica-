all: compila

compila: main.o viewport.o
	gcc main.o viewport.o -o prog

main.o: main.c
	gcc -c main.c

viewport.o: viewport.c
	gcc -c viewport.c

rm:
	rm viewport.o main.o prog


del: 
	del viewport.o main.o prog
