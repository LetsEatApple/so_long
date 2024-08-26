/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:23:22 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/02 12:05:58 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

/* int main()
{
	char *dt = NULL;
	char *sc = NULL;
	memcpy(dt, sc, 1);
	printf("%s\n", dt);
	
	char *d = NULL;
	char *s = NULL;
	ft_memcpy(d, s, 1);
	printf("%s\n", d);
	
	return 0; 
} */