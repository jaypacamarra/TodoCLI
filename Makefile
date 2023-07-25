CC := gcc
CFLAGS := -Wall -pedantic -g3

all: build run

build: main.c
	$(CC) $(CFLAGS) -o out main.c

run: out
	@./out
