/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:04:59 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/02 14:17:09 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *string)
{
	int	out;
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	out = 0;
	while (string[i] == 32 || (string[i] <= 13 && string[i] >= 9))
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			flag *= -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		out *= 10;
		out += string[i] - '0';
		i++;
	}
	out *= flag;
	return (out);
}
