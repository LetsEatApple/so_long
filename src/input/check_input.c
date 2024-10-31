/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:58:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/31 17:57:12 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_if_file(char *filename)
{
	char	*extension;
	int		i;
	int		j;

	extension = ".ber";
	j = 4;
	i = ft_strlen(filename);
	while (i > 0 && j > 0)
	{
		if (extension[j -1] != filename[i -1])
			return (false);
		i--;
		j--;
	}
	return (true);
}

int	get_buffer_size(const char *file)
{
	void	*buffer;
	int		fd;
	int		size;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit (0);
	}
	size = 0;
	i = 1;
	while (i != 0)
	{
		buffer = malloc(1 +1);
		i = read(fd, buffer, 1);
		size = size + i;
		free(buffer);
	}
	close(fd);
	return (size);
}

void	get_map(t_pro *game, char *file)
{
	int		size;
	int		fd;
	char	*strmap;

	size = get_buffer_size(file);
	if (size < 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
	strmap = malloc(size +1);
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, strmap, size) < 0)
	{
		free(strmap);
		close(fd);
		exit(1);
	}
	strmap[size] = '\0';
	close(fd);
	game->map = ft_split(strmap, '\n');
	free(strmap);
}

void	error_exit(t_pro *game, char error_code)
{
	ft_putstr_fd("Error\n", 2);
	if (error_code == 'r')
		ft_putstr_fd("'Map must be rectangular'", 2);
	else if (error_code == 'i')
		ft_putstr_fd("'Invalid component was passed'", 2);
	else if (error_code == 'c')
		ft_putstr_fd("'Too few/many components'", 2);
	else if (error_code == 'w')
		ft_putstr_fd("'Map must be surrounded by walls'", 2);
	else if (error_code == 'p')
		ft_putstr_fd("'No valid path'", 2);
	free_splits(game->map);
	exit(0);
}

void	check_input(t_pro *game)
{
	if (check_if_rectangle(game->map) == false)
		error_exit(game, 'r');
	if (check_components(game->map) == false)
		error_exit(game, 'i');
	if (check_ammount(game->map) == false)
		error_exit(game, 'c');
	if (check_wall(game->map) == false)
		error_exit(game, 'w');
	if (check_path(game->map) == false)
		error_exit(game, 'p');
	return ;
}
