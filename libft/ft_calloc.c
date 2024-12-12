/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:48:47 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 15:59:52 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
