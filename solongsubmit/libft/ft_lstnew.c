/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:15:58 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/18 21:07:15 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

/* int main()
{
	t_list *head = NULL;
	int a = 0;
	head = ft_lstnew(&a);
	printf("%i\n", *(int*)head->content);
	return (0);
} */

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */