CC = gcc

SRC = gnl/get_next_line.c gnl/get_next_line_utils.c
			\ src/valid_map.c src/map_parsing.c src/render_utils.c 
			\ src/main.c

OBJ = $(SRC:.c=.o)

NAME = so_long
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
