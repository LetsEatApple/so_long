/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:36:57 by lhagemos          #+#    #+#             */
/*   Updated: 2024/10/14 11:47:52 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_surrogates	get_surrogates(char **map, t_queue *current)
{
	int				x;
	int				y;
	t_surrogates	neighbor;

	x = current->x;
	y = current->y;
	neighbor.s1.x = x;
	neighbor.s1.y = y -1;
	neighbor.s1.c = map[y -1][x];
	neighbor.s2.x = x +1;
	neighbor.s2.y = y;
	neighbor.s2.c = map[y][x +1];
	neighbor.s3.x = x;
	neighbor.s3.y = y +1;
	neighbor.s3.c = map[y +1][x];
	neighbor.s4.x = x -1;
	neighbor.s4.y = y;
	neighbor.s4.c = map[y][x -1];
	return (neighbor);
}

int	check_queue(t_queue *q, t_position s)
{
	t_queue	*ptr;

	ptr = q;
	while (ptr != NULL)
	{
		if (ptr -> y == s.y && ptr -> x == s.x)
			return (true);
		ptr = ptr -> next;
	}
	return (false);
}

void	check_surrogates(t_queue **q, t_surrogates neighbor)
{
	t_queue	*new;

	if (neighbor.s1.c != '1' && check_queue(*q, neighbor.s1) == false)
	{
		new = newnode(neighbor.s1.y, neighbor.s1.x, neighbor.s1.c);
		add_node(q, new);
	}
	if (neighbor.s2.c != '1' && check_queue(*q, neighbor.s2) == false)
	{
		new = newnode(neighbor.s2.y, neighbor.s2.x, neighbor.s2.c);
		add_node(q, new);
	}
	if (neighbor.s3.c != '1' && check_queue(*q, neighbor.s3) == false)
	{
		new = newnode(neighbor.s3.y, neighbor.s3.x, neighbor.s3.c);
		add_node(q, new);
	}
	if (neighbor.s4.c != '1' && check_queue(*q, neighbor.s4) == false)
	{
		new = newnode(neighbor.s4.y, neighbor.s4.x, neighbor.s4.c);
		add_node(q, new);
	}
}

/* int count_unvisited(t_queue *q)
{
	int count;
	t_queue *ptr;

	count = 0;
	ptr = q;
	while (ptr != NULL)
	{
		if (ptr -> v == 'N')
			count++;
		ptr = ptr->next;
	}
	return (count);
} */

 void	print_queue(t_queue *q)
{
	t_queue *ptr;

	ptr = q;
	while (ptr != NULL)
	{
		printf("queue: %c\n", ptr->c);
		ptr = ptr->next;
	}
}

t_queue	*get_path(char **map)
{
	t_queue			*q;
	t_queue			*current;
	t_surrogates	neighbor;
	t_position		p;
	int				c;

	p = get_position(map, 'P');
	q = newnode(p.y, p.x, p.c);
	current = q;
	while (current != NULL)
	{
		neighbor = get_surrogates(map, current);
		check_surrogates(&q, neighbor);
		print_queue(q);
		current = current -> next;
		if (current && current -> c == 'E')
			current = current -> next;
	}
	return (q);
}

int	check_path(char **map)
{
	t_queue	*queue;
	t_queue	*ptr;
	int		collect;
	int		count;

	queue = get_path(map);
	collect = countc(map, 'C');
	ptr = queue;
	count = 0;
	while (ptr != NULL)
	{
		if (ptr -> c == 'C' || ptr -> c == 'E')
			count++;
		ptr = ptr -> next;
	}
	clearqueue(&queue);
	if (count == collect +1)
		return (true);
	return (false);
}
