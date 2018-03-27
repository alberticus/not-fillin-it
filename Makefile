NAME = fillit
HEADER = -c
CONFIG = gcc $(HEADER) -Wall -Wextra -Werror $(SRC)
CONFIG2 =
SRC = .c\

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
