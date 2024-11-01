/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:10:47 by lhagemos          #+#    #+#             */
/*   Updated: 2024/04/27 21:35:39 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		res;
	size_t	zero;

	zero = 0;
	if (n == zero)
		return (0);
	i = 0;
	while (i < n -1)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			break ;
		s1++;
		s2++;
		i++;
	}
	res = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (res);
}

/* int main()
{
	char s1[] = "Hablo";
	char s2[] = "Hallo";
	char s3[] = "Hablo";
	char s4[] = "Hallo";
	printf("%d\n", ft_memcmp(s1, s2, 5));
	printf("%d\n", memcmp(s3, s4, 3));
	return 0;
} */