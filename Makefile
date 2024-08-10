CC ?= gcc
BIN := bin/db

all:
	$(CC) -o $(BIN) $(wildcard src/*.c)

run: all
	./$(BIN)

clean:
	rm $(BIN) | true
