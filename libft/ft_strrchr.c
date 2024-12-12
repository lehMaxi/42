/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:02:18 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 16:27:50 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *string, int c)
{
	int		i;
	char	*out;

	i = 1;
	while (string[i - 1])
	{
		if (string[ft_strlen(string) - i] == (char)c)
		{
			out = (char *)string + ft_strlen(string) - i;
			return (out);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&string[ft_strlen(string)]);
	return (NULL);
}
/*
#include <stdio.h>
int     main(void)
{
        printf("%s",ft_strrchr("bonjour", 's'));
        return (0);
}
*/
