/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:44:10 by lhagemos          #+#    #+#             */
/*   Updated: 2024/08/22 13:36:50 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putint(int i)
{
	int		size;
	char	*nb;

	nb = ft_itoa(i);
	ft_putstr_fd(nb, 1);
	size = ft_strlen(nb);
	free(nb);
	return (size);
}
