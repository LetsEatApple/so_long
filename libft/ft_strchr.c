/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:54:29 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/02 13:11:12 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

/* int main()
{
	int c = 97;
	const char s[] = "Hallo";
	int d = 97;
	const char s1[] = "Hallo";
	printf("%s", ft_strchr(s, '\0'));
	printf("%s", strchr(s1, '\0'));
	return 0;
} */
