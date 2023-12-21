CC = gcc
SRC = $(wildcard ./src/*.c)
Target = bin/main
CFLAGS = -I ./inc/ -L ./lib
OBJ=$(patsubst %c,%o,$(SRC))

$(Target):$(SRC)
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	$(RM) $(Target)
