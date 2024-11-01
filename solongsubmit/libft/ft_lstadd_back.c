/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:55 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/20 00:32:45 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new;
	}
}

/* int main()
{
	
	t_list *head;
	head = malloc(sizeof(t_list));
	head -> content = "Hallo ";
	head -> next = NULL;

	t_list *node;
	node = ft_lstnew("World");
	head -> next = node;

	t_list *node2;
	node2 = ft_lstnew(" ");
	node -> next = node2;
	
	t_list *new;
	new = ft_lstnew("!");
	
	ft_lstadd_back(&head, new);
	
	t_list	*ptr;
	ptr = ft_lstlast(head);
	printf("%s\n", (char *)ptr -> content);
	return (0);
} */