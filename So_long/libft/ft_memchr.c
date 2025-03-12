/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:03:32 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 16:28:46 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	char	*needles;
	size_t	i;

	needles = (char *)s;
	i = 0;
	while (i < n)
	{
		if (*needles == (char)c)
			return (needles);
		i++;
		needles++;
	}
	return (NULL);
}
