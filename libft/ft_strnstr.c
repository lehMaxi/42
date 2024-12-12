/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:04:34 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 12:15:34 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < n)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i + j < n && little[j])
				j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		j = 0;
		i++;
	}
	return (NULL);
}
