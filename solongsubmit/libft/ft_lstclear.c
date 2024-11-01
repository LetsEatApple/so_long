/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:17:46 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/20 00:33:19 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	while (*lst)
	{
		ptr = (*lst)-> next;
		ft_lstdelone(*lst, del);
		(*lst) = ptr;
	}
}

/* void	del(void *content)
{
	free(content);
}

int main()
{
	t_list *head;
	head = ft_lstnew(ft_strdup("a"));

	t_list *node1;
	node1 = ft_lstnew(ft_strdup("a"));
	head -> next = node1;

	t_list *node2;
	node2 = ft_lstnew(ft_strdup("a"));
	node1 -> next = node2;

	t_list *ptr;
	ptr = head;
	while (ptr != NULL)
	{
		printf("%s", (char *)ptr -> content);
		ptr = ptr -> next;
	}
	if (ptr == NULL)
		printf("end reached\n");
	ft_lstclear(&head, del);
	ptr = head;
	while (ptr != NULL)
	{
		printf("%s", (char *)ptr -> content);
		ptr = ptr -> next;
	}
	if (ptr == NULL)
		printf("end reached\n");
	return 0;
} */