# Ligar todos
all: biblioteca.o main.o
	gcc -std=c11 -o exec main.o biblioteca.o

# Gerar arquivo objeto da biblioteca
biblioteca.o: biblioteca.c
	gcc -std=c11 -c biblioteca.c -o biblioteca.o

# Gerar arquivo objeto da main
main.o: main.c
	gcc -std=c11 -c main.c -o main.o

clean:
	rm *.o exec
#      (aceite qualquer coisa antes de).o