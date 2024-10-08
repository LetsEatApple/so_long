/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:00:06 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/08 17:21:51 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	check_next(t_program *p, char key)
{
	t_position	player;

	player = get_position(p->map, 'P');
	if (key == 'W')
		return (p->map[player.y -1][player.x]);
	if (key == 'A')
		return (p->map[player.y][player.x -1]);
	if (key == 'S')
		return (p->map[player.y +1][player.x]);
	if (key == 'D')
		return (p->map[player.y][player.x +1]);
	return ('N');
}



void	apply_w(t_program *p, char next_field)
{
	t_position	player;
	int			c_left;

	player = get_position(p->map, 'P');
	c_left = countc(p->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		p->map[player.y][player.x] = '0';
		p->map[player.y -1][player.x] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
	if (next_field == 'E' && c_left == 0)
	{
		p->sp.monke = ft_new_sprite(p->mlx, "src/exit.xpm");
		p->map[player.y][player.x] = '0';
		p->map[player.y -1][player.x] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
}

void	apply_a(t_program *p, char next_field)
{
	t_position	player;
	int			c_left;

	player = get_position(p->map, 'P');
	c_left = countc(p->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		p->map[player.y][player.x] = '0';
		p->map[player.y][player.x -1] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
	if (next_field == 'E' && c_left == 0)
	{
		p->sp.monke = ft_new_sprite(p->mlx, "src/exit.xpm");
		p->map[player.y][player.x] = '0';
		p->map[player.y][player.x -1] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
}

void	apply_s(t_program *p, char next_field)
{
	t_position	player;
	int			c_left;

	player = get_position(p->map, 'P');
	c_left = countc(p->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		p->map[player.y][player.x] = '0';
		p->map[player.y +1][player.x] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
	if (next_field == 'E' && c_left == 0)
	{
		p->sp.monke = ft_new_sprite(p->mlx, "src/exit.xpm");
		p->map[player.y][player.x] = '0';
		p->map[player.y +1][player.x] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
}

void	apply_d(t_program *p, char next_field)
{
	t_position	player;
	int			c_left;
	t_image		black;
	t_image		end;

	player = get_position(p->map, 'P');
	c_left = countc(p->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		p->map[player.y][player.x] = '0';
		p->map[player.y][player.x +1] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
	if (next_field == 'E' && c_left == 0)
	{
		p->sp.monke = ft_new_sprite(p->mlx, "src/exit.xpm");
		p->map[player.y][player.x] = '0';
		p->map[player.y][player.x +1] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
		black = ft_new_image(p->mlx, p->win_size.x, p->win_size.y);
		mlx_put_image_to_window(p->mlx, p->win.ptr, black.ptr, 0, 0);
		end = ft_new_sprite(p->mlx, "src/end.xpm");
		mlx_put_image_to_window(p->mlx, p->win.ptr, end.ptr, 0, 0);
	}
}

int	event(int key, t_program *p)
{
	char		next_field;

	if (key == 53)
	{
		free_splits(p->map);
		exit (0);
	}
	if (key == 13)
	{
		next_field = check_next(p, 'W');
		apply_w(p, next_field);
	}
	if (key == 0)
	{
		next_field = check_next(p, 'A');
		apply_a(p, next_field);
	}
	if (key == 1)
	{
		next_field = check_next(p, 'S');
		apply_s(p, next_field);
	}
	if (key == 2)
	{
		next_field = check_next(p, 'D');
		apply_d(p, next_field);
	}
	return (0);
}

void	call_event(t_program p)
{
	mlx_key_hook(p.win.ptr, event, &p);
}
