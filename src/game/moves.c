/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:07:38 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/22 13:42:41 by lhagemos         ###   ########.fr       */
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

	if (countc(p->map, 'E') == 0)
		return ;
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
		p->sp.monke = ft_new_sprite(p->mlx, "src/textures/exit.xpm");
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

	if (countc(p->map, 'E') == 0)
		return ;
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
		p->sp.monke = ft_new_sprite(p->mlx, "src/textures/exit.xpm");
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

	if (countc(p->map, 'E') == 0)
		return ;
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
		p->sp.monke = ft_new_sprite(p->mlx, "src/textures/exit.xpm");
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

	if (countc(p->map, 'E') == 0)
		return ;
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
		p->sp.monke = ft_new_sprite(p->mlx, "src/textures/exit.xpm");
		p->map[player.y][player.x] = '0';
		p->map[player.y][player.x +1] = 'P';
		p->counter = p->counter +1;
		ft_printf("%d\n", p->counter);
		generate_map(*p);
	}
}
