# Makefile
FLAGS = -g -fsanitize=address
FILE = main.c

.PHONY: clean

all: worst year ever

worst: 
	@clang++ loading.cpp -o forever
	@./forever
year:
	@gcc $(FILE) $(FLAGS)
	@./a.out
ever:
	@clear

clean:
	rm -rf a.out
