/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:47:44 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/18 20:43:17 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	(*del)(lst -> content);
	free(lst);
}

/* void	del(void *content)
{
	free(content);
}

int main()
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
	{
		printf("allocation failed\n");
		return 1;
	}
	node -> content = malloc(100);
	if (!node -> content)
	{
		free(node);
		return 1;
		printf("allocation failed\n");
	}
	ft_lstdelone(node, del);
		printf("node deleted\n");
	return 0;
} */