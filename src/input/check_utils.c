/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:38:39 by lhagemos          #+#    #+#             */
/*   Updated: 2024/11/02 13:44:15 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_newline(char *strmap)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (strmap[i] && strmap[0] == '\n')
		return (false);
	while (strmap[i])
	{
		if (count == 2)
			return (false);
		if (strmap[i +1] == '\0' && strmap[i] == '\n')
			return (false);
		if (strmap[i] == '\n')
			count ++;
		else
			count = 0;
		i++;
	}
	return (true);
}

t_position	get_position(char **map, char c)
{
	int			y;
	int			x;
	t_position	comp;

	y = 0;
	comp.x = 0;
	comp.y = 0;
	comp.c = 'N';
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
