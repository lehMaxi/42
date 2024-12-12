/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:59 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/02 18:22:30 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	dlen;

	i = 0;
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + ft_strlen(src));
	while ((i + dlen < size - 1) && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + ft_strlen(src));
}
/*
#include <stdio.h>
int	main(void)
	char stuff[] = "";
	char moar[] = "mew";

	printf("%"s)*/
