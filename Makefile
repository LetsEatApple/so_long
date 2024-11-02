
CC = cc

CFLAGS = -Wall -Wextra -Werror

#for Mac:
#MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

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

#For Mac:
#%.o: %.c
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#
#$(NAME): $(OBJ)
#	$(MAKE) -C ./libft
#	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#For Linux:
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C ./libft --silent
	$(MAKE) -C ./mlx --silent
	$(CC) $(OBJ) libft/libft.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	$(MAKE) clean -C ./libft --silent
	$(MAKE) clean -C ./mlx --silent
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft --silent
	$(MAKE) clean -C ./mlx --silent
	rm -f $(NAME)

re: fclean all
