/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 10:55:50 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/01 17:31:34 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*int main()
{
	char *str;
	str = (char *)ft_calloc(10, sizeof(char));
	printf("%lu\n", sizeof(str));
	printf("%s\n", str);
	char *s;
	s = (char *)calloc(10, sizeof(char));
	printf("%lu\n", sizeof(s));
	printf("%s\n", s);
	free(str);
	free(s);
	return 0;
}*/