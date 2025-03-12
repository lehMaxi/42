/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:16 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 18:43:47 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	char	*nuff;
	char	*buff;
	size_t	i;

	buff = (char *)src;
	nuff = (char *)dest;
	i = 1;
	if (dest == src)
		return (dest);
	if (dest < src || dest >= src + n)
	{
		dest = ft_memcpy(dest, src, n);
	}
	else
	{
		while (buff && i <= n)
		{
			nuff[n - i] = buff[n - i];
			i++;
		}
	}
	return (dest);
}
