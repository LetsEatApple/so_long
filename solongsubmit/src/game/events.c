/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:00:06 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/31 17:35:50 by lhagemos         ###   ########.fr       */
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
