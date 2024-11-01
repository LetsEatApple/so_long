/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:15:11 by lhagemos          #+#    #+#             */
/*   Updated: 2024/08/22 13:37:02 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print(const char *format, va_list *args, int i)
{
	int	size;

	size = 0;
	if (format[i] == 'd' || format[i] == 'i')
		size = ft_putint(va_arg(*args, int));
	else if (format[i] == 'u')
		size = ft_putu(va_arg(*args, unsigned int));
	else if (format[i] == 's')
		size = ft_putstring(va_arg(*args, char *));
	else if (format[i] == 'c')
		size = ft_putc(va_arg(*args, int));
	else if (format[i] == '%')
		size = ft_putc('%');
	else if (format[i] == 'x')
		size = ft_puthexa_lw(va_arg(*args, int), &size);
	else if (format[i] == 'X')
		size = ft_puthexa_up(va_arg(*args, int), &size);
	else if (format[i] == 'p')
		size = ft_putptr(va_arg(*args, void *));
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	args;

	va_start(args, format);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			size = size + print(format, &args, i);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			size++;
		}
		i++;
	}
	va_end(args);
	return (size);
}

/* #include <stdio.h>
#include <limits.h>
int main()
{
	// int hexa = -0xA;
	// char *s = "";
	// unsigned int u = -1;
	int d = ft_printf("Ergebnis_my: %x und %x\n", 0, -1);
	int f = printf("Ergebnis_og: %x und %x\n", 0, -1);
	printf("%d\n" , d);
	printf("%d\n", f);
	//ft_printf("Ergebnis_my: p = %p, c = %c, s = %s, u = %u\n", s, 'h', s, u);
	//printf("Ergebnis_og: p = %p, c = %c, s = %s, u = %u\n", s, 'h', s, u); 
	return 0;
} */