all: Casamento.o main.c
	gcc -o casamento main.c Casamento.o
Casamento.o: Casamento.c
	gcc -o Casamento.o -c Casamento.c

clean:
	del *.o main

run:
	main
