/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:12:39 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/23 17:49:52 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 15
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <stdbool.h>
# include <errno.h>
# include "../libft/ft_printf.h"
# include "../libft/libft.h"
# include "mlx.h"

typedef struct s_position
{
	int		x;
	int		y;
	char	c;
}	t_position;

typedef struct s_surrogates
{
	t_position	s1;
	t_position	s2;
	t_position	s3;
	t_position	s4;
}	t_surrogates;

typedef struct s_queue
{
	struct s_queue	*prev;
	int				y;
	int				x;
	int				c;
	struct s_queue	*next;
}	t_queue;
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_window
{
	void		*ptr;
	t_vector	size;
}	t_window;

typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	char		*pixels;
	int			bpp; //bits_per_pixel
	int			l_size; //line_size
	int			endian;
}	t_image;

typedef struct s_sprite
{
	t_image	wall;
	t_image	space;
	t_image	coin;
	t_image	monke;
	t_image	exit;
	t_image	end;
	t_image	end_up;
	t_image	mv;
	t_image	black;
}	t_sprite;

typedef struct s_program
{
	void		*mlx;
	t_window	win;
	t_vector	win_size;
	t_sprite	sp;
	t_vector	pos;
	char		**map;
	int			counter;
}	t_program;

int			check_if_file(char *filename);
int			get_buffer_size(const char *file);
char		**get_map(char *file);
int			get_arrsize(char **map);
void		free_splits(char **splits);
size_t		check_if_rectangle(char **map);
int			check_char(char c);
int			check_components(char **map);
int			check_wall(char **map);
int			check_ammount(char **map);
void		error_exit(char **map, char code);
void		check_input(char **map);
int			countc(char **map, char c);
t_position	get_position(char **map, char c);
int			check_path(char **map);
void		add_node(t_queue **top, t_queue *new);
t_queue		*newnode(int y, int x, char c);
void		clearqueue(t_queue **top);
int			ft_close();
t_window	ft_new_window(t_program p, char *name);
t_image		ft_new_image(void *mlx, int width, int height);
t_image		ft_new_sprite(void *mlx, char *path);
char		check_next(t_program *p, char key);
int			event(int key, t_program *p);
void		call_event(t_program p);
void		generate_map(t_program p);
int			ft_update(t_program *p);
char		check_next(t_program *p, char key);
void		apply_w(t_program *p, char next_field);
void		apply_a(t_program *p, char next_field);
void		apply_s(t_program *p, char next_field);
void		apply_d(t_program *p, char next_field);
int			destroy_game(t_program *pro);

#endif