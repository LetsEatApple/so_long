/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:00 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/07 16:24:18 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//mlx_hook(void *window, int event, int mask, int (*f)(), void *param);

int ft_close(t_program *p)
{
	free_splits(p->map);
	exit(0);
}

t_window	ft_new_window(t_program p, char *name)
{
	t_window	window;

	window.ptr = mlx_new_window(p.mlx, p.win_size.x, p.win_size.y, name);
	window.size.x = p.win_size.x;
	window.size.y = p.win_size.y;
	mlx_hook(window.ptr, 17, 0, ft_close, &p);
	return (window);
}

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image img;
	img.ptr = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

/* int start_game()
{
	t_program program;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1980, 1080, "So Long");
	program.sprite = ft_new_sprite(program.mlx, "block.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	mlx_put_image_to_window(program.mlx, program.window.ptr, program.sprite.ptr, program.sprite_position.x, program.sprite_position.y);
	mlx_loop(program.mlx);
} */