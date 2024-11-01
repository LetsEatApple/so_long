/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:37:00 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/31 18:37:39 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_win_size(t_pro *game)
{
	t_vector	size;

	size.x = ft_strlen(game->map[0]) * 50;
	size.y = get_arrsize(game->map) * 50;
	game->size = size;
}

void	get_sprites(t_pro *g)
{
	int	w;
	int	h;

	g->space = mlx_xpm_file_to_image(g->mlx, "src/textures/space.xpm", &w, &h);
	g->wall = mlx_xpm_file_to_image(g->mlx, "src/textures/block_b.xpm", &w, &h);
	g->monke = mlx_xpm_file_to_image(g->mlx, "src/textures/monke.xpm", &w, &h);
	g->coin = mlx_xpm_file_to_image(g->mlx, "src/textures/coin.xpm", &w, &h);
	g->exit = mlx_xpm_file_to_image(g->mlx, "src/textures/rocket.xpm", &w, &h);
	g->end = mlx_xpm_file_to_image(g->mlx, "src/textures/end.xpm", &w, &h);
}

void	destroy_sprites(t_pro *game)
{
	if (game->space)
		mlx_destroy_image(game->mlx, game->space);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->monke)
		mlx_destroy_image(game->mlx, game->monke);
	if (game->coin)
		mlx_destroy_image(game->mlx, game->coin);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->end)
		mlx_destroy_image(game->mlx, game->end);
}

void	place_image(t_pro *g, void *img, int x, int y)
{
	x = x * 50;
	y = y * 50;
	mlx_put_image_to_window(g->mlx, g->win, img, x, y);
}

void	generate_map(t_pro *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '0')
				place_image(g, g->space, x, y);
			if (g->map[y][x] == '1')
				place_image(g, g->wall, x, y);
			if (g->map[y][x] == 'E')
				place_image(g, g->exit, x, y);
			if (g->map[y][x] == 'C')
				place_image(g, g->coin, x, y);
			if (g->map[y][x] == 'P')
				place_image(g, g->monke, x, y);
			if (g->map[y][x] == 'X')
				place_image(g, g->end, x, y);
			x++;
		}
		y++;
	}
}
