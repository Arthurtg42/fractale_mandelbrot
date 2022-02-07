# $(BIN) est le nom du binaire généré
BIN = mandelbrot

# $(OBJECTS) sont les objets qui seront générés après la compilation
OBJECTS = config.o entree_sortie.o image.o main.o

# $(CC) est le compilateur utilisé mais aussi le linker
CC = gcc

# $(CFLAGS) sont les options du compilateur
CFLAGS = -std=c99 -Wall -Wextra -Werror

# all est la première règle à être exécutée car elle est la première
# dans le fichier Makefile.
all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lm -o $(BIN)

# règles pour chaque module
config.o: config.c config.h
	$(CC) $(CFLAGS) -c config.c
image.o: image.c image.h
	$(CC) $(CFLAGS) -c image.c
entree_sortie.o: entree_sortie.c entree_sortie.h image.h
	$(CC) $(CFLAGS) -c entree_sortie.c
main.o: main.c entree_sortie.h image.h config.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm *.o $(BIN)
