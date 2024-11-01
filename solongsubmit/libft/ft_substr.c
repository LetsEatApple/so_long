/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:37:00 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/20 00:41:08 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	msize(char const *s, unsigned int start, size_t len)
{
	int		size;
	size_t	l;

	l = ft_strlen(s) - start;
	if (len > l)
		size = l;
	else
		size = len;
	return (size +1);
}

static int	validstart(char const *s, unsigned int start)
{
	if (start >= ft_strlen(s))
		return (1);
	else
		return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			size;
	size_t			j;

	i = 0;
	j = 0;
	if (validstart(s, start) != 0 || s == 0 || len == 0)
		size = 1;
	else
		size = msize(s, start, len);
	sub = (char *)malloc(size);
	if (sub == 0)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

//  int main()
// {
//  	char str[30] = "";
//  	char *sub;
//  	sub = ft_substr(str, 1, 20);
//  	printf("%s\n", sub);
//  	free(sub);
//  	return 0;
// } 
/* int main()
{
 	char str[] = "Hallo World!";
 	char *sub;
 	sub = ft_substr(str, 6, 5);
 	printf("%s\n", sub);
 	free(sub);
 	return 0;
} */