/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:06:37 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/06 16:48:17 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char const *s1, char const *set, int i)
{
	int	occ;
	int	j;

	occ = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
			occ++;
		j++;
	}
	return (occ);
}

static int	start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (checkset(s1, set, i) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	end(char const *s1, char const *set)
{
	int	n;

	n = ft_strlen(s1) -1;
	while (n > 0)
	{
		if (checkset(s1, set, n) == 0)
			break ;
		n--;
	}
	return (n);
}

static int	msize(char const *s1, char const *set)
{
	int	size;

	size = end(s1, set) - start(s1, set);
	return (size +1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	size;
	size_t	s;

	s = start(s1, set);
	size = msize(s1, set);
	trim = ft_substr(s1, s, size);
	return (trim);
}

// int main()
// {
// 	char str[] = "halblo"; //"lorem \n ipsum \t dolor \n sit \t amet"
// 	char set[] = "hol"; // "te"
// 	char *t = ft_strtrim(str, set);
// 	printf("%s\n", t);
// 	free(t);
// 	return 0;
// }