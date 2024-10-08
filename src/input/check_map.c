/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:34:50 by lhagemos          #+#    #+#             */
/*   Updated: 2024/09/23 14:17:14 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	check_if_rectangle(char **map)
{
	size_t	size;
	int		i;

	if (get_arrsize(map) < 2)
		return (false);
	size = ft_strlen(map[0]);
	i = 1;
	while (map[i] != 0)
	{
		if (ft_strlen(map[i]) != size)
			return (false);
		i++;
	}
	return (true);
}

int	check_char(char c)
{
	char	*components;
	int		match;
	int		i;

	components = "01CEP";
	i = 0;
	match = 0;
	while (components[i])
	{
		if (c == components[i])
			match++;
		i++;
	}
	if (match == 0)
		return (false);
	return (true);
}

int	check_components(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j])
		{
			if (check_char(map[i][j]) == false)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	check_wall(char **map)
{
	int	y;
	int	x;
	int	l;
	int	h;

	l = ft_strlen(map[0]) - 1;
	h = get_arrsize(map) - 1;
	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x])
		{
			if ((y == 0 || x == 0 || x == l || y == h) && map[y][x] != '1')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

int	check_ammount(char **map)
{
	int	p;
	int	e;
	int	c;

	p = countc(map, 'P');
	e = countc(map, 'E');
	c = countc(map, 'C');
	if (p != 1 || e != 1 || c < 1)
		return (false);
	return (true);
}
