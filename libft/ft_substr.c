/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:53:33 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 18:29:48 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	mal_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		mal_len = ft_strlen(s) - start;
	else
		mal_len = len;
	i = 0;
	sub = (char *)malloc(mal_len + 1);
	if (sub == NULL)
		return (NULL);
	while (i < mal_len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*str = "banana split the difference";
	unsigned int	st = 6;
	size_t		l = 5;
	printf("%s", ft_substr(str, st, l));
	return (0);
}*/
