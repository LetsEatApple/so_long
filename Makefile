
CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = src/main.c \
src/input/check_input.c \
src/input/check_map.c \
src/input/check_path.c \
src/input/check_utils.c \
src/game/events.c \
src/game/graphics.c \
src/game/moves.c

OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#for Linux:
#%.o: %.c
#	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#
#$(NAME): $(OBJ)
#	$(MAKE) -C ./libft
#	$(CC) $(OBJ) libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
