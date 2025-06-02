# Compilador
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Objetos
OBJS = diretores.o filmes.o

all: app2 app3

app2: app2.o diretores.o
	$(CC) $(CFLAGS) -o app2 app2.o diretores.o

app3: app3.o $(OBJS)
	$(CC) $(CFLAGS) -o app3 app3.o $(OBJS)

diretores.o: diretores.c diretores.h
	$(CC) $(CFLAGS) -c diretores.c

filmes.o: filmes.c filmes.h diretores.h
	$(CC) $(CFLAGS) -c filmes.c

app2.o: app2.c diretores.h
	$(CC) $(CFLAGS) -c app2.c

app3.o: app3.c filmes.h diretores.h
	$(CC) $(CFLAGS) -c app3.c

clean:
	rm -f *.o app2 app3
