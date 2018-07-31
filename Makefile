NAME = lem-in

FILE_C =  main.c room.c link.c bfs.c create_rd.c

FILE_O = $(FILE_C:.c=.o)

GCC = gcc

FLAG = -Wall -Wextra -Werror -g

LIB_INC = -I libft/

LIBNAME = ./libft/libft.a

all: $(NAME)

$(LIBNAME): ./libft/libft.h
	make -C ./libft

$(NAME): $(LIBNAME) $(FILE_O)
	$(GCC) $(FILE_O) ./libft/libft.a -o $(NAME)

%.o: %.c
	$(GCC) $(FLAG) -c $< $(LIB_INC)

clean:
	make -C ./libft clean
	rm -f $(FILE_O)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
	make -C ./libft fclean