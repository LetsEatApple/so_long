/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:42:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/08 17:19:24 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_arrsize(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != 0)
	{
		count++;
		i++;
	}
	return (count);
}

void	free_splits(char **splits)
{
	int	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

t_vector	get_mapsize(char **map)
{
	t_vector	map_size;

	map_size.x = ft_strlen(map[0]) * 50;
	map_size.y = get_arrsize(map) * 50;
	return (map_size);
}

void	generate_map(t_program p)
{
	int	x;
	int	y;
	int	w;
	int	h;

	y = 0;
	while (p.map[y])
	{
		x = 0;
		while (p.map[y][x])
		{
			w = x * 50;
			h = y * 50;
			if (p.map[y][x] == '1')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.wall.ptr, w, h);
			if (p.map[y][x] != '1')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.space.ptr, w, h);
			if (p.map[y][x] == 'E')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.exit.ptr, w, h);
			if (p.map[y][x] == 'C')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.coin.ptr, w, h);
			if (p.map[y][x] == 'P')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.monke.ptr, w, h);
			x++;
		}
		y++;
	}
}

t_program	collect_data(t_program p, char **map)
{
	p.mlx = mlx_init();
	p.win_size = get_mapsize(map);
	p.map = map;
	p.counter = 0;
	p.win = ft_new_window(p, "So Long");
	p.sp.wall = ft_new_sprite(p.mlx, "src/block.xpm");
	p.sp.space = ft_new_sprite(p.mlx, "src/space.xpm");
	p.sp.exit = ft_new_sprite(p.mlx, "src/rocket.xpm");
	p.sp.coin = ft_new_sprite(p.mlx, "src/coin.xpm");
	p.sp.monke = ft_new_sprite(p.mlx, "src/monke.xpm");
	return (p);
}

/* int	get_keycode(int keycode, void *param)
{
	printf("Key pressed: %d\n", keycode);
	return (0);
} */

int	main(int argc, char **argv)
{
	char **map;
	int	fd;
	t_program pro;
	int x;
	int y;

	if (argc != 2)
		return (0);
	if (check_if_file(argv[1]) == false)
	{
		ft_putstr_fd("Error\n'no '*.ber' file passed'", 2);
		return (0);
	}
	map = get_map(argv[1]);
	check_input(map);
	pro = collect_data(pro, map);
	/* if (window_size.x * 50 > 1920 || window_size.y > 1080)
	{
		
	} */
	generate_map(pro);
	// mlx_key_hook(pro.win.ptr, get_keycode, NULL); -> print the keycode
	call_event(pro);
	mlx_loop(pro.mlx);
	free_splits(map);
	return (0);
}



