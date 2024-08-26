/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:45:38 by lhagemos          #+#    #+#             */
/*   Updated: 2024/05/24 18:26:06 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb > 9)
	{
		c = nb % 10 + 48;
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
	}
	else
		c = nb + 48;
	ft_putchar_fd(c, fd);
}

/* int main()
{
	ft_putnbr_fd(-422, 1);
	return 0;
} */