/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:04:13 by mlehmann          #+#    #+#             */
/*   Updated: 2024/11/27 20:00:31 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*fir;
	unsigned char	*sec;
	size_t			i;

	fir = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (fir[i] != sec[i])
			return (fir[i] - sec[i]);
		i++;
	}
	return (0);
}
