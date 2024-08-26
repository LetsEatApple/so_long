/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:01:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/04/23 13:45:42 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i +1 < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

/* int main()
{
	char dst[] = "Bye";
	const char src[] = "Hallo";
	printf("%s\n", dst);
	printf("%d\n", ft_strlcpy(dst, src, 6));
	printf("%s\n", dst);
	return (0);
} */