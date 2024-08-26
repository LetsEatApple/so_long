/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:38:45 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/01 17:22:06 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

/* #include <string.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 10;
	int arr[n];
	int nb = 10;
	int test[nb];
	ft_memset(arr, 10, n*sizeof(arr[0]));
	memset(test, 10, nb*sizeof(test[0]));
	while (i < n)
	{
		printf("%i", arr[i]);
		i++;
	}
	printf("\n");
	while (j < nb)
	{
		printf("%i", test[j]);
		j++;
	}
	return 0;	
} */
/* #include <string.h>

int main()
{
	char str[] = "Hallo";
	char test[] = "Hallo";
	ft_memset(str, 'p', 4*sizeof(char));
	memset(test, 'p', 4*sizeof(char));
	printf("%s\n%s", str, test);
	return 0;
} */