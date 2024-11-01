/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:41:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/18 20:44:42 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst -> content));
	if (!new)
		return (0);
	head = new;
	lst = lst -> next;
	while (lst)
	{
		new -> next = ft_lstnew(f(lst -> content));
		if (!new -> next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		lst = lst -> next;
		new = new -> next;
	}
	new -> next = NULL;
	return (head);
}

/*  void	*f(void *content)
{
	free(content);
	content = ft_strdup("!");
	return(content);
}

void	del(void *content)
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
	t_list *new;
	new = ft_lstmap(head, f, del);
	ptr = new;
	while (ptr != NULL)
	{
		printf("%s", (char *)ptr -> content);
		ptr = ptr -> next;
	}
	return 0;
}  */