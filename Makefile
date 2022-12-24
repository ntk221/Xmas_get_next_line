CC = gcc
FLAGS = -Wall -Wextra -Werror

TESTS = ./tests/*

all:
	$(CC) $(FLAGS) main.c -o minishell

rm:
	rm minishell

test: $(TESTS)

PHONY: all clean test