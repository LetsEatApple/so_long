/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:38:57 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/02 18:48:38 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	o;

	i = 0;
	o = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			o = i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else if (o != -1)
		return ((char *)&s[o]);
	else
		return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	int c = 'b';
// 	const char s[] = "bonjour";
// 	printf("%s", ft_strrchr(s, c));
// 	return 0;
// }