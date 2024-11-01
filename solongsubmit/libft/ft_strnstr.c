/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:57:04 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/02 20:44:59 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

//#include <bsd/string.h>
// int main()
// {
// 	char b[] = "lorem ipsum dolor sit amet";
// 	char l[] = "dolor";
// 	char big[] = "lorem ipsum dolor sit amet";
// 	char lill[] = "dolor";
// 	// printf("%s\n", strnstr(big, lill, 15));
// 	printf("%s\n", ft_strnstr(b, l, 15));
// 	return 0;
// }