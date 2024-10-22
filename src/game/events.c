/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:00:06 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/22 13:44:24 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//for mac:
// W = 13
// A = 0
// S = 1
// D = 2
// ESC = 53

int	ft_update(t_program *p)
{
	static int	frame;
	t_image		black;
	t_vector	pos;

	black = ft_new_image(p->mlx, p->win_size.x, p->win_size.y);
	pos.x = (p->win_size.x / 2) - (p->sp.end_up.size.x / 2);
	pos.y = (p->win_size.y / 2) - (p->sp.end_up.size.y / 2);
	mlx_put_image_to_window(p->mlx, p->win.ptr, black.ptr, 0, 0);
	frame++;
	mlx_put_image_to_window(p->mlx, p->win.ptr, p->sp.end_up.ptr, pos.x, pos.y);
	if (frame >= ANIMATION_FRAMES)
	{
		mlx_put_image_to_window(p->mlx, p->win.ptr, p->sp.mv.ptr, pos.x, pos.y);
		frame = 0;
	}
	return (0);
}

int	event(int key, t_program *p)
{
	if (countc(p->map, 'E') == 0)
		mlx_loop_hook(p->mlx, ft_update, p);
	if (key == 65307)
	{
		free_splits(p->map);
		exit (0);
	}
	if (key == 119)
		apply_w(p, check_next(p, 'W'));
	if (key == 97)
		apply_a(p, check_next(p, 'A'));
	if (key == 115)
		apply_s(p, check_next(p, 'S'));
	if (key == 100)
		apply_d(p, check_next(p, 'D'));
	return (0);
}

void	call_event(t_program p)
{
	mlx_key_hook(p.win.ptr, event, &p);
}
