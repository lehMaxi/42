/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:00:44 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/09 11:07:53 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *adress)
{
	int	control;

	control = 0;
	control += ft_putstring("0x");
	if (control < 0)
		return (control);
	control += ft_puthex((unsigned int)adress);
	if (control < 2)
		return (-1);
	return (control);
}
