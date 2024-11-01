/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:47:30 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/15 15:05:51 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	ptr = lst;
	while (ptr != NULL)
	{
		if (ptr -> next == NULL)
			break ;
		ptr = ptr -> next;
	}
	return (ptr);
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
	
	t_list	*ptr;
	ptr = ft_lstlast(&head);
	printf("%s\n", (char *)ptr -> content);
	return (0);
} */