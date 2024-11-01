/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:54:30 by lhagemos          #+#    #+#             */
/*   Updated: 2024/08/22 13:37:47 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_hex(unsigned long int hexa)
{
	char	c;

	if (hexa < 10)
		c = hexa + 48;
	else
		c = hexa + 87;
	ft_putchar_fd(c, 1);
}

static	int	puthex(unsigned long int dec, int *size)
{
	unsigned long int	hexa;
	unsigned long int	res;
	unsigned long int	res2;

	if (dec > 0)
	{
		res = dec / 16;
		res2 = res * 16;
		hexa = dec - res2;
		dec = res;
		(*size)++;
		puthex(dec, size);
		print_hex(hexa);
	}
	return (*size);
}

int	ft_putptr(void *ptr)
{
	unsigned long int	address;
	int					size;

	size = 2;
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		size = 5;
	}
	else
	{
		address = (unsigned long int)ptr;
		ft_putstr_fd("0x", 1);
		puthex(address, &size);
	}
	return (size);
}

/* int main()
{
	printf("%p\n", -1);
	ft_putptr(-1);
	return 0;
} */