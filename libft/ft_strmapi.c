/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:35:20 by mlehmann          #+#    #+#             */
/*   Updated: 2024/11/28 11:11:27 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		i;

	i = 0;
	out = (char *)malloc(ft_strlen(s) + 1);
	if (out == NULL)
		return (NULL);
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
/*
#include <stdio.h>
char	plus(unsigned int i, char c)
{
	if (c + i < 127)
		c += i;
	return (c);
}

int main(void)
{
	char	*stuff = "09876543210987654321                                          ";
	char	*more_stuff;

	printf("%s\n", stuff);
	more_stuff = ft_strmapi(stuff, plus);
	printf("%s\n", more_stuff);
}*/
