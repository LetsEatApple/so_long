/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:58:10 by lhagemos          #+#    #+#             */
/*   Updated: 2024/11/02 12:37:42 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	**to_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static char	*get_pointer(char const *s, char c, int i)
{
	char	*ptr;
	int		j;
	int		size;
	int		save;

	save = i;
	size = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		size++;
	}
	ptr = (char *)malloc(size + 1);
	if (ptr == 0)
		return (0);
	j = 0;
	while (s[save] && s[save] != c)
	{
		ptr[j++] = s[save++];
	}
	ptr[j] = '\0';
	return (ptr);
}

static char	**split(char const *s, char c, char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
		{
			arr[j] = get_pointer(s, c, i);
			if (!arr[j])
				return (to_free(arr));
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = (char **)malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	arr = split(s, c, arr);
	return (arr);
}

// int main()
// {
// 	char s[] = "bla bla bla";
// 	char c = ' ';
// 	char **arr;
// 	int i = 0;
// 	arr = ft_split(s, c);
// 	if (!arr[0])
// 		printf("ok\n");
// 	while (arr[i] != 0)
// 	{
// 		printf("%s\n", arr[i]);
// 		/* free(arr[i]); */
// 		i++;
// 	}
// 	free(arr);
// 	return 0;
// }