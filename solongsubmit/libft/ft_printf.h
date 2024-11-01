/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhagemos <lhagemos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:38:26 by lhagemos          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:56 by lhagemos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_puthexa_lw(unsigned int dec, int *size);
int	ft_puthexa_up(unsigned int dec, int *size);
int	ft_putptr(void *ptr);
int	ft_putint(int i);
int	ft_putstring(char *s);
int	ft_putc(char c);
int	ft_putu(unsigned int n);

#endif