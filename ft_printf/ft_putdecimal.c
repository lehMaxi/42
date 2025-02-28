/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:08:10 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/09 14:50:17 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int i)
{
	int	control;

	control = 0;
	if (i < 0)
		control = ft_putchar('-');
	if (control < 0)
		return (control);
	if (i < 0)
		control = ft_putint((i / 10 * -1));
	if (i > 0)
		control = ft_putint(i / 10);
	if (control < 0)
		return (control);
	if (i < 0)
		control = ft_putchar((i % 10 * -1) + '0');
	if (i > 0)
		control = ft_putchar(i % 10 + '0');
	return (control);
}

int	ft_putlong(unsigned int i)
{
	int	control;

	control = 0;
	if (i > 0)
		control = ft_putlong(i / 10);
	if (control < 0)
		return (control);
	if (i > 0)
		control = ft_putchar(i % 10 + '0');
	return (control);
}

int	numlen(int i, unsigned int u)
{
	unsigned int	num;
	unsigned int	len;

	len = 0;
	if (i < 0)
	{
		num = i / -10;
		len += 2;
	}
	else if (i > 0)
		num = i;
	else
		num = u;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	ft_putdecimal(int i, unsigned int u)
{
	int	control;

	if (i == 0 && u == 0)
		return (ft_putchar('0'));
	else if (u == 0)
		control = ft_putint(i);
	else
		control = ft_putlong(u);
	if (control < 0)
		return (control);
	return (numlen(i, u));
}
