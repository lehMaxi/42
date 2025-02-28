/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:43:33 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/13 15:02:55 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_sort(char c, va_list arg)
{
	int	control;

	control = 0;
	if (c == 'c')
		control = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		control = ft_putstring(va_arg(arg, char *));
	else if (c == 'p')
		control = ft_putpointer(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		control = ft_putdecimal(va_arg(arg, int), 0);
	else if (c == 'u')
		control = ft_putdecimal(0, va_arg(arg, unsigned int));
	else if (c == 'x')
		control = ft_puthex(va_arg(arg, int), 'x');
	else if (c == 'X')
		control = ft_puthex(va_arg(arg, int), 'X');
	else if (c == '%')
		control = ft_putchar('%');
	return (control);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		control;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			control = ft_putchar(*str);
			str++;
		}
		else
		{
			control = call_sort(*(str + 1), ap);
			str += 2;
		}
		if (control < 0)
			return (control);
		i += control;
	}
	va_end(ap);
	return (i);
}
