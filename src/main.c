/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:42:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/11/04 16:26:26 by lhagemos         ###   ########.fr       */
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

int	ft_exit(char exit_code)
{
	if (exit_code == 'a')
		ft_putstr_fd("Error\n'Too few/many arguments'\n", 2);
	if (exit_code == 'f')
		ft_putstr_fd("Error\n'File is not valid'\n", 2);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_pro	game;

	if (argc != 2)
		ft_exit('a');
	ft_memset(&game, 0, sizeof(t_pro));
	if (check_if_file(argv[1]) == false)
	{
		ft_putstr_fd("Error\n'no '*.ber' file passed'\n", 2);
		return (0);
	}
	get_map(&game, argv[1]);
	get_win_size(&game);
	check_input(&game);
	game.counter = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.size.x, game.size.y, "So Long");
	get_sprites(&game);
	generate_map(&game);
	mlx_key_hook(game.win, event, &game);
	mlx_hook(game.win, 17, 0, exit_loop, &game);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
