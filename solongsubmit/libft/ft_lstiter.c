/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:08:58 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/20 00:33:31 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr != NULL)
	{
		(*f)(ptr -> content);
		ptr = ptr -> next;
	}
}

/* void	f(void *content)
{
	free(content);
	content = ft_strdup("!");
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
	ft_lstiter(head, f);
	ptr = head;
	while (ptr != NULL)
	{
		printf("%s", (char *)ptr -> content);
		ptr = ptr -> next;
	}
	return 0;
} */