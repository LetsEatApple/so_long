/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:38:39 by lhagemos          #+#    #+#             */
/*   Updated: 2024/09/23 14:23:39 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	countc(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_position	get_position(char **map, char c)
{
	int			y;
	int			x;
	t_position	comp;

	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x]) == c)
			{
				comp.y = y;
				comp.x = x;
				comp.c = c;
				return (comp);
			}
			x++;
		}
		y++;
	}
	return (comp);
}

void	add_node(t_queue **top, t_queue *new)
{
	t_queue	*ptr;

	if (!top || !new)
		return ;
	ptr = *top;
	if (*top == NULL)
		*top = new;
	else
	{
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new;
		new -> prev = ptr;
	}
}

t_queue	*newnode(int y, int x, char c)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	if (!new)
		return (0);
	new -> prev = NULL;
	new -> y = y;
	new -> x = x;
	new -> c = c;
	new -> v = 'N';
	new -> next = NULL;
	return (new);
}

void	clearqueue(t_queue **top)
{
	t_queue	*ptr;

	ptr = *top;
	while (ptr != NULL)
	{
		if (ptr->next == NULL)
		{
			free(ptr);
			break ;
		}
		ptr = ptr->next;
		free(ptr->prev);
	}
}
