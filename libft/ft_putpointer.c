/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:00:44 by mlehmann          #+#    #+#             */
/*   Updated: 2025/02/17 12:31:33 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptrlen(intptr_t u)
{
	intptr_t		num;
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

int	putlonghex(intptr_t i)
{
	int	control;

	control = 0;
	if (i > 15)
		control = putlonghex(i / 16);
	if (control < 0)
		return (control);
	if (i % 16 < 10)
		control = ft_putchar((i % 16) + '0');
	else
		control = ft_putchar((i % 16) + 87);
	if (control < 0)
		return (control);
	return (ptrlen(i));
}

int	ft_putpointer(void *adress)
{
	int			control;
	intptr_t	buffer;

	control = 0;
	if (adress == NULL)
		return (ft_putstring("(nil)"));
	else
		control += ft_putstring("0x");
	if (control < 0)
		return (control);
	buffer = (intptr_t) adress;
	control += putlonghex(buffer);
	if (control < 2)
		return (-1);
	return (control);
}
