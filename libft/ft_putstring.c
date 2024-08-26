/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:50:43 by lhagemos          #+#    #+#             */
/*   Updated: 2024/08/22 13:37:56 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putstring(char *s)
{
	int	size;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		size = 6;
	}
	else
	{
		ft_putstr_fd(s, 1);
		size = ft_strlen(s);
	}
	return (size);
}
