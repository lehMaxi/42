/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:33:58 by mlehmann          #+#    #+#             */
/*   Updated: 2024/11/27 19:40:31 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*out;

	out = (char *)malloc(intlen(n) + 1);
	if (out == NULL)
		return (NULL);
	out[intlen(n)] = '\0';
	if (n == 0)
		out[0] = '0';
	if (n < 0)
		out[0] = '-';
	while (n != 0)
	{
		if (n > 0)
			out[intlen(n) - 1] = n % 10 + '0';
		else
		{
			out[intlen(n) - 1] = (n % 10 * -1) + '0';
		}
		n /= 10;
	}
	return (out);
}
/*
#include <stdio.h>

int	main(void)
{
	int i;
	i = 4582384;
	printf("%s", ft_itoa(i));
}*/
