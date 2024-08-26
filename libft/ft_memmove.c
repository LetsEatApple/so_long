/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:02:20 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/08 17:34:03 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}

// int main()
// {
// 	char s[] = "Hallo wie gehts";
// 	char d[] = "hotel des Grauens";
// 	char sr[] = "Hallo wie gehts";
// 	char de[] = "hotel des Grauens";
// 	ft_memmove((void *)&s[1], (void *)&s[0], 17);
// 	// memmove((void *)&sr[1], (void *)&sr[0], 17);
// 	printf("%s\n", s);
// 	printf("%s\n", sr);
// }
	// if (n > ft_strlen(s))
	// 	n = ft_strlen(s);