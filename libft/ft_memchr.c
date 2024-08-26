/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:46:06 by lhagemos          #+#    #+#             */
/*   Updated: 2024/04/27 21:35:52 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((unsigned char *)s);
		s = (unsigned char *)s +1;
		i++;
	}
	return (NULL);
}

/* int main()
{
	char str[] = "Hallo";
	char c = 'a';
	char s[] = "Hallo";
	char ch = 'a';
	printf("%s\n", ft_memchr(str, c, 1));
	printf("%s\n", memchr(s, ch, 1));
	return 0;
} */