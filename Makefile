CC = gcc
FLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(FLAGS) main.c -o minishell

rm:
	rm minishell

PHONY: all clean