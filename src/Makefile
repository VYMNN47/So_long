CC = cc

SRC = ../gnl/get_next_line.c ../gnl/get_next_line_utils.c \
			 valid_map.c map_parsing.c render_utils.c utils.c is_beatable.c \
			 main.c move_player.c errors.c utils1.c utils2.c utils3.c

OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
