/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:42:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/14 01:25:52 by lhagemos         ###   ########.fr       */
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

t_program	collect_data(t_program p, char **map)
{
	p.mlx = mlx_init();
	p.win_size = get_mapsize(map);
	p.map = map;
	p.counter = 0;
	p.win = ft_new_window(p, "So Long");
	p.sp.wall = ft_new_sprite(p.mlx, "src/textures/block.xpm");
	p.sp.space = ft_new_sprite(p.mlx, "src/textures/space.xpm");
	p.sp.exit = ft_new_sprite(p.mlx, "src/textures/rocket.xpm");
	p.sp.coin = ft_new_sprite(p.mlx, "src/textures/coin.xpm");
	p.sp.monke = ft_new_sprite(p.mlx, "src/textures/monke.xpm");
	if (p.win_size.x < 350 || p.win_size.y < 300)
	{
		p.sp.end_up = ft_new_sprite(p.mlx, "src/textures/end_up_mini.xpm");
		p.sp.mv = ft_new_sprite(p.mlx, "src/textures/end_down_mini.xpm");
	}
	else
	{
		p.sp.end_up = ft_new_sprite(p.mlx, "src/textures/end_up.xpm");
		p.sp.mv = ft_new_sprite(p.mlx, "src/textures/end_down.xpm");
	}
	return (p);
}

/* int	get_keycode(int keycode, void *param)
{
	printf("Key pressed: %d\n", keycode);
	return (0);
} */

// mlx_key_hook(pro.win.ptr, get_keycode, NULL); -> print the keycode
int	main(int argc, char **argv)
{
	char		**map;
	int			fd;
	t_program	pro;
	int			x;
	int			y;

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
	generate_map(pro);
	call_event(pro);
	mlx_loop(pro.mlx);
	free_splits(map);
	return (0);
}

/* if (window_size.x * 50 > 1920 || window_size.y > 1080)
	{
		
	} */
