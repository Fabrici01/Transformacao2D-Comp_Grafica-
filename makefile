all: compila

compila: main.o transformacoes.o
	gcc main.o transformacoes.o -o prog

main.o: main.c
	gcc -c main.c
transformacoes.o: transformacoes.c
	gcc -c transformacoes.c
rm:
	rm main.o transformacoes.o prog
del: 
	del main.o transformacoes.o prog
