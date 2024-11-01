/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:21:35 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/15 14:44:28 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		size;

	size = 0;
	if (lst == NULL)
		return (0);
	ptr = lst;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr -> next;
	}
	return (size);
}

/* int main()
{
	t_list head;

	head.content = "Hallo ";
	head.next = NULL;

	t_list node;
	node.content = "World ";
	head.next = &node;
	node.next = NULL;

	t_list node2;
	node2.content = "!";
	node.next = &node2;
	node2.next = NULL;

	printf("%d\n", ft_lstsize(&head));
	return (0);
} */

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */