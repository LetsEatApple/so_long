/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:06:33 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/13 15:12:29 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)malloc(ft_strlen(s) +1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* char f(unsigned int index, char ch)
	{
		ch = 97;
		return (ch);
	}

int main()
{
	char s[] = "Hallo";
	char *ptr;
	
	printf("%s\n", s);
	ptr = ft_strmapi(s, f);
	printf("%s\n", ptr);
	printf("%s\n", s);
	free(ptr);
	return (0);
} */