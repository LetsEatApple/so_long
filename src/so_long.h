/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:12:39 by lhagemos          #+#    #+#             */
/*   Updated: 2024/11/02 13:49:54 by lhagemos         ###   ########.fr       */
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

typedef struct s_pro
{
	void		*mlx;
	void		*win;
	t_vector	size;
	void		*wall;
	void		*space;
	void		*coin;
	void		*monke;
	void		*exit;
	void		*end;
	char		**map;
	int			counter;
}	t_pro;

int			check_if_file(char *filename);
int			get_buffer_size(const char *file);
void		get_map(t_pro *game, char *file);
int			get_arrsize(char **map);
void		free_splits(char **splits);
size_t		check_if_rectangle(char **map);
int			check_char(char c);
int			check_components(char **map);
int			check_wall(char **map);
int			check_ammount(char **map);
void		error_exit(t_pro *game, char code);
void		check_input(t_pro *game);
int			countc(char **map, char c);
t_position	get_position(char **map, char c);
int			check_path(char **map);
void		add_node(t_queue **top, t_queue *new);
t_queue		*newnode(int y, int x, char c);
void		clearqueue(t_queue **top);
char		check_next(t_pro *p, char key);
int			event(int key, t_pro *p);
void		generate_map(t_pro *game);
int			ft_update(t_pro *p);
char		check_next(t_pro *p, char key);
void		apply_w(t_pro *p, char next_field);
void		apply_a(t_pro *p, char next_field);
void		apply_s(t_pro *p, char next_field);
void		apply_d(t_pro *p, char next_field);
int			exit_loop(t_pro *game);
void		get_sprites(t_pro *g);
void		destroy_sprites(t_pro *game);
void		get_win_size(t_pro *game);
int			check_newline(char *strmap);

#endif