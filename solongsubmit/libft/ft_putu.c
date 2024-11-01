/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:09:46 by lhagemos          #+#    #+#             */
/*   Updated: 2024/08/22 13:38:01 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	msize(unsigned int n)
{
	int				count;

	if (n == 0)
		count = 1;
	else
		count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_utoa(unsigned int n)
{
	char			*ptr;
	int				i;
	unsigned int	nb;
	int				len;

	nb = n;
	i = 0;
	len = msize(n);
	ptr = (char *)malloc(sizeof(char) * len +1);
	if (ptr == 0)
		return (0);
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

int	ft_putu(unsigned int n)
{
	int		size;
	char	*nb;

	nb = ft_utoa(n);
	ft_putstr_fd(nb, 1);
	size = ft_strlen(nb);
	free(nb);
	return (size);
}
