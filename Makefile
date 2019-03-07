##
## EPITECH PROJECT, 2018
## Project MiniLibC
## File description:
## Makefile
##

LD            = ld

ASM            = nasm

ASMFLAGS    = -f elf64

CFLAGS        = -fPIC -shared

SRC =           memcpy.asm      \
                memset.asm      \
                strchr.asm      \
                strcmp.asm      \
                strncmp.asm     \
                strlen.asm      \
                strcasecmp.asm  \
                rindex.asm      \
                strstr.asm      \
                strpbrk.asm     \
                strcspn.asm     \
                memmove.asm

OBJ            = $(SRC:.asm=.o)

NAME        = libasm.so

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(OBJ)
	rm -f a.out

fclean: clean
	rm -f $(NAME)

re:	fclean all

test: re
	gcc -Wall -Wextra -W -fno-builtin -g3 mainTest.c -o test

