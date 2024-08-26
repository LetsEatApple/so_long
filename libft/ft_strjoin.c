/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:17:39 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/03 15:33:42 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*join;

	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(size +1);
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

/* int main ()
{
	char s1[] = "Hallo ";
	char s2[] = "World!";
	char *j;
	j = ft_strjoin(s1, s2);
	printf("%s\n", j);
	free(j);
	return 0;
} */