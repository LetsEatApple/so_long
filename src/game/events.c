/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:00:06 by lhagemos          #+#    #+#             */
/*   Updated: 2024/11/04 16:24:15 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//for mac:
// W = 13
// A = 0
// S = 1
// D = 2
// ESC = 53

/* int	ft_update(t_pro *p)
{
	static int	frame;
	t_vector	pos;

	p->sp.black = ft_new_image(p->mlx, p->win_size.x, p->win_size.y);
	pos.x = (p->win_size.x / 2) - (p->sp.end_up.size.x / 2);
	pos.y = (p->win_size.y / 2) - (p->sp.end_up.size.y / 2);
	mlx_put_image_to_window(p->mlx, p->win.ptr, p->sp.black.ptr, 0, 0);
	frame++;
	mlx_put_image_to_window(p->mlx, p->win.ptr, p->sp.end_up.ptr, pos.x, pos.y);
	if (frame >= ANIMATION_FRAMES)
	{
		mlx_put_image_to_window(p->mlx, p->win.ptr, p->sp.mv.ptr, pos.x, pos.y);
		frame = 0;
	}
	return (0);
} */

int	exit_loop(t_pro *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	exit_game(t_pro *game)
{
	destroy_sprites(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_splits(game->map);
	return (0);
}

int	countc(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	event(int key, t_pro *game)
{
	int	check;

	check = countc(game->map, 'E');
	if (key == 65307)
		exit_loop(game);
	if (check != 0 && key == 119)
		apply_w(game, check_next(game, 'W'));
	if (check != 0 && key == 97)
		apply_a(game, check_next(game, 'A'));
	if (check != 0 && key == 115)
		apply_s(game, check_next(game, 'S'));
	if (check != 0 && key == 100)
		apply_d(game, check_next(game, 'D'));
	return (0);
}
