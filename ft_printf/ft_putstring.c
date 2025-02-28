/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:53:01 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/21 12:39:20 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *str)
{
	int	i;
	int	control;

	control = 0;
	i = 0;
	if (!str)
		i = ft_putstring("(null)");
	else
	{
		while (str && str[i])
		{
			control += ft_putchar((int)str[i]);
			i++;
			if (control < 0)
				return (control);
			control = 0;
		}
	}
	return (i);
}
