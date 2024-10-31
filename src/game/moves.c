/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:07:38 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/31 17:08:36 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	check_next(t_pro *game, char key)
{
	t_position	pos;

	pos = get_position(game->map, 'P');
	if (key == 'W')
		return (game->map[pos.y -1][pos.x]);
	if (key == 'A')
		return (game->map[pos.y][pos.x -1]);
	if (key == 'S')
		return (game->map[pos.y +1][pos.x]);
	if (key == 'D')
		return (game->map[pos.y][pos.x +1]);
	return ('N');
}

void	apply_w(t_pro *game, char next_field)
{
	t_position	pos;
	int			c_left;

	if (countc(game->map, 'E') == 0)
		return ;
	pos = get_position(game->map, 'P');
	c_left = countc(game->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y -1][pos.x] = 'P';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		generate_map(game);
	}
	if (next_field == 'E' && c_left == 0)
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y -1][pos.x] = 'X';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		ft_printf("Congrats! You made it!\n");
		generate_map(game);
	}
}

void	apply_a(t_pro *game, char next_field)
{
	t_position	pos;
	int			c_left;

	if (countc(game->map, 'E') == 0)
		return ;
	pos = get_position(game->map, 'P');
	c_left = countc(game->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y][pos.x -1] = 'P';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		generate_map(game);
	}
	if (next_field == 'E' && c_left == 0)
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y][pos.x -1] = 'X';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		ft_printf("Congrats! You made it!\n");
		generate_map(game);
	}
}

void	apply_s(t_pro *game, char next_field)
{
	t_position	pos;
	int			c_left;

	if (countc(game->map, 'E') == 0)
		return ;
	pos = get_position(game->map, 'P');
	c_left = countc(game->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y +1][pos.x] = 'P';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		generate_map(game);
	}
	if (next_field == 'E' && c_left == 0)
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y +1][pos.x] = 'X';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		ft_printf("Congrats! You made it!\n");
		generate_map(game);
	}
}

void	apply_d(t_pro *game, char next_field)
{
	t_position	pos;
	int			c_left;

	if (countc(game->map, 'E') == 0)
		return ;
	pos = get_position(game->map, 'P');
	c_left = countc(game->map, 'C');
	if (next_field != '1' && next_field != 'E')
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y][pos.x +1] = 'P';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		generate_map(game);
	}
	if (next_field == 'E' && c_left == 0)
	{
		game->map[pos.y][pos.x] = '0';
		game->map[pos.y][pos.x +1] = 'X';
		game->counter = game->counter +1;
		ft_printf("%d\n", game->counter);
		ft_printf("Congrats! You made it!\n");
		generate_map(game);
	}
}
