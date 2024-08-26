/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:47:04 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/16 20:24:19 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

/* int main()
{
	t_list *head;
	head = ft_lstnew("a");
	
	t_list *node1;
	node1 = ft_lstnew("l");
	head -> next = node1;

	t_list *node2;
	node2 = ft_lstnew("l");
	node1 -> next = node2;

	t_list *new;
	new = ft_lstnew("B");

	t_list *ptr;
	ptr = head;

	while (ptr != NULL)
	{
		printf("%s", (char *)ptr -> content);
		ptr = ptr -> next;
	}
	
	ptr = head;
	ft_lstadd_front(&head, new);
	ptr = head;
	while (ptr != NULL)
	{
		printf("%s", (char *)ptr -> content);
		ptr = ptr -> next;
	}
	return 0;
} */