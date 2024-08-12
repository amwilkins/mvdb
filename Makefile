CC ?= gcc
BIN := bin/db
DIR = $(HOME)/$(BIN)

ifeq ($(DEBUG),1)
   OPTS = -g
endif

all:
	$(CC) $(OPTS) -o $(DIR) $(wildcard src/*.c)

run: all
	./$(DIR)

clean:
	rm $(DIR) | true
