/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:50:45 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/13 19:43:43 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* void f(unsigned int index, char *ch)
	{
		*ch = 97;
	}

int main()
{
	char s[] = "Hallo";
	printf("%s\n", s);
	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
} */