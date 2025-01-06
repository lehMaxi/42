/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:43:33 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/06 12:56:05 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	call_sort(char %, va_list *arg)
{
	if (% == 'c')
		ft_putchar(va_arg(arg, char));
	else if (% == 's')
		ft_putstring(va_arg(arg, char*));
	else if (% == 'p')
		ft_putpointer(va_arg(arg, void*));
	else if (% == 'd' || % == 'i')
		ft_putdecimal(va_arg(arg, int), 0);
	else if (% == 'u')
		ft_putdecimal(0, va_arg(arg, unsigned int));
	else if (% == 'x')
		ft_puthex(va_arg(arg, int), 'x');
	else if (% == 'X')
		ft_puthex(va_arg(arg, int), 'X');
	else if (% == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
		}
		else
		{
			call_sort(str[i+1], *ap);
		}
	}
}
