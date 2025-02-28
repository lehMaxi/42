/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:13:40 by mlehmann          #+#    #+#             */
/*   Updated: 2025/02/17 12:30:57 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexlen(unsigned int u)
{
	unsigned int	num;
	unsigned int	len;

	len = 0;
	num = u;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int i, char c)
{
	int	control;

	control = 0;
	if (i > 15)
		control = ft_puthex(i / 16, c);
	if (control < 0)
		return (control);
	if (i % 16 < 10)
		control = ft_putchar((i % 16) + '0');
	else if (c == 'X')
		control = ft_putchar((i % 16) + 55);
	else if (c == 'x')
		control = ft_putchar((i % 16) + 87);
	if (control < 0)
		return (control);
	return (hexlen(i));
}
