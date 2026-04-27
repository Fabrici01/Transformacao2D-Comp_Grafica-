all: compila

compila: main.o
	gcc main.o -o prog

main.o: main.c
	gcc -c main.c
rm:
	rm main.o prog
del: 
	del main.o prog
