NAME = fillit
LIBFT = libft/libft.a
CONFIG = gcc -I libft/ -Wall -Wextra -Werror $(SRC) -c
CONFIG2 = gcc -L libft -lft $(OBJ) -o $(NAME)
SRC = main.c\
      normalize.c\
      pieces.c\
      validate.c\
      solver.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME):
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
