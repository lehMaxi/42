/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:56:02 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/06 12:57:29 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "how_long.h"

void	ft_itos(char *out, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		out[0] = '0';
		i++;
	}
	while (n != 0)
	{
		if (n > 0)
			out[imp(n) - 1] = n % 10 + '0';
		else
		{
			out[imp(n) - 1] = (n % 10 * -1) + '0';
		}
		n /= 10;
		i++;
	}
	out[i] = '\0';
}

int	imp(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		return (0);
	if (num / 10 > 0)
	{
		i += imp(num / 10);
	}
	return (i);
}

