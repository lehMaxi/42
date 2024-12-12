/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:22 by mlehmann          #+#    #+#             */
/*   Updated: 2024/11/27 19:02:28 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*zeros;
	size_t	i;

	i = 0;
	zeros = (char *)s;
	while (i < n)
	{
		zeros[i] = '\0';
		i++;
	}
}
