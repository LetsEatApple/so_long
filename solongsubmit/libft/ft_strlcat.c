/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:43:20 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/02 11:50:54 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst);
	if (size == 0)
		return (ft_strlen(src));
	if (size <= len)
		return (size + ft_strlen(src));
	i = 0;
	while (len + i < size -1 && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (len + i);
}

/*#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>

int main()
{
	char dst[] = "";
	const char src[] = "B";
	char d[] = "";
	const char s[] = "B";
	printf("%s\n", dst);
	printf("%zu\n", ft_strlcat(dst, src, 0));
	printf("%zu\n", strlcat(d, s, 0));
	printf("%s\n", dst);
	printf("%s\n", d);
	return 0;
}*/