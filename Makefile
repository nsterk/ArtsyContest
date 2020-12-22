# Makefile
FLAGS = -g -fsanitize=address
FILE = main.c
FILE2 = 2021.c

.PHONY: clean

all: make longest year ever

longest: 
	@clang++ loading.cpp -o forever
	@./forever
year:
	@gcc $(FILE) $(FLAGS)
	@./a.out
ever:
	@clear

2021:
	@gcc $(FILE2) $(FLAGS) -o 2021
	@./2021
clean:
	rm -rf a.out 2021
