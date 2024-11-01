/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:28:48 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/03 15:49:38 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		res;
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n -1 && s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	res = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
	return (res);
}

// #include <string.h>
// int main()
// {
// 	const char *s1 = "test\200";
// 	const char *s2 = "test\0";
// 	const char *s3 = "test\200";
// 	const char *s4 = "test\0";
// 	printf("%d\n", ft_strncmp(s1, s2, 6));
// 	printf("%d\n", strncmp(s3, s4, 6));
// 	return 0;
// }