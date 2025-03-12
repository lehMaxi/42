/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:44 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 11:02:26 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	char	*buff;
	char	*nuff;
	size_t	i;

	buff = (char *)src;
	nuff = (char *)dest;
	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		nuff[i] = buff[i];
		i++;
	}
	dest = nuff;
	return (dest);
}
