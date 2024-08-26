/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:46:04 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/20 00:48:37 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	msize(int n)
{
	int			count;
	long int	nb;

	nb = n;
	if (n == 0)
		count = 1;
	else
		count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static void	make_positive(char *ptr, long int *nb, int *i)
{
	*nb *= -1;
	ptr[0] = '-';
	*i = 1;
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			i;
	long int	nb;
	int			len;

	nb = n;
	i = 0;
	len = msize(n);
	ptr = (char *)malloc(sizeof(char) * len +1);
	if (ptr == 0)
		return (0);
	if (nb < 0)
		make_positive(ptr, &nb, &i);
	while (len-- > i)
	{
		if (nb > 9)
		{
			ptr[len] = nb % 10 + 48;
			nb = nb / 10;
		}
		else
			ptr[len] = nb + 48;
	}
	ptr[msize(n)] = '\0';
	return (ptr);
}

/* int main()
{
	char *s;
 	s = ft_itoa(-50);
 	printf("%s\n", s);
 	free(s);
 	return 0;
} */