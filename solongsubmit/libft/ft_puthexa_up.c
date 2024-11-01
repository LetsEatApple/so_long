/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:31:06 by lhagemos          #+#    #+#             */
/*   Updated: 2024/08/22 13:37:35 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_hexa(unsigned int hexa)
{
	char	c;

	if (hexa < 10)
		c = hexa + 48;
	else
		c = hexa + 55;
	ft_putchar_fd(c, 1);
}

static int	puthex(unsigned int dec, int *size)
{
	unsigned int	hexa;
	unsigned int	res;
	unsigned int	res2;

	if (dec > 0)
	{
		res = dec / 16;
		res2 = res * 16;
		hexa = dec - res2;
		dec = res;
		(*size)++;
		puthex(dec, size);
		print_hexa(hexa);
	}
	return (*size);
}

int	ft_puthexa_up(unsigned int dec, int *size)
{
	if (dec == 0)
	{
		print_hexa(0);
		(*size)++;
	}
	else
		puthex(dec, size);
	return (*size);
}

/* int main()
{
	ft_puthexa_up(5474756);
	return 0;
} */