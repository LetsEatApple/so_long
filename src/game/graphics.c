/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:00 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/23 17:48:29 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//free_splits(p->map);
/* int	ft_close(t_program *p)
{
	destroy_game(p);
} */

t_window	ft_new_window(t_program p, char *name)
{
	t_window	window;

	window.ptr = mlx_new_window(p.mlx, p.win_size.x, p.win_size.y, name);
	window.size.x = p.win_size.x;
	window.size.y = p.win_size.y;
	mlx_hook(window.ptr, 17, 0, destroy_game, &p);
	return (window);
}

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.ptr = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.ptr, &img.bpp, &img.l_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bpp, &img.l_size, &img.endian);
	return (img);
}

void	generate_map(t_program p)
{
	t_vector	pos;
	int			w;
	int			h;

	pos.y = 0;
	while (p.map[pos.y])
	{
		pos.x = 0;
		while (p.map[pos.y][pos.x])
		{
			w = pos.x * 50;
			h = pos.y * 50;
			mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.space.ptr, w, h);
			if (p.map[pos.y][pos.x] == '1')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.wall.ptr, w, h);
			if (p.map[pos.y][pos.x] == 'E')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.exit.ptr, w, h);
			if (p.map[pos.y][pos.x] == 'C')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.coin.ptr, w, h);
			if (p.map[pos.y][pos.x] == 'P')
				mlx_put_image_to_window(p.mlx, p.win.ptr, p.sp.monke.ptr, w, h);
			pos.x++;
		}
		pos.y++;
	}
}
