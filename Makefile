CC = gcc
FLAGS = -Wall -Wextra -Werror

TESTS 	= ./tests/*
SPLIT 	= ./split/split.c
COM	  	= ./command_execution/*
BUILTIN = ./builtin_commands/echo/*

all:
	$(CC) $(FLAGS) $(SPLIT) $(COM) $(BUILTIN) main.c -lreadline -o minishell

rm:
	rm minishell

norm:
	norminette

split_test: $(TESTS) $(SPLIT)
	$(CC) $(TESTS) $(SPLIT) -o split_test
	./split_test
	rm split_test

PHONY: all clean test