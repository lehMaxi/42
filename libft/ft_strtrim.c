/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:31:08 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 18:40:39 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	front_comp(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			counter++;
			i++;
			j = -1;
		}
		j++;
	}
	return (counter);
}

static int	back_comp(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	j = 0;
	counter = 0;
	while (set[j])
	{
		if (s1[ft_strlen(s1) - i] == set[j])
		{
			counter++;
			i++;
			j = -1;
		}
		j++;
	}
	return (counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*out;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	size -= front_comp(s1, set);
	size -= back_comp(s1, set);
	if (size <= 0)
		return (ft_strdup(""));
	size++;
	out = (char *)malloc(size);
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, s1 + front_comp(s1, set), size);
	out[size] = '\0';
	return (out);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*s1 = "big banana big";
	char const	*set = "gbig";
	char const	*set2 = "gi";
	char	*out;
	char	*out2;

	out = ft_strtrim(s1, set);
	out2 = ft_strtrim(s1, set2);
	printf("%s\n", out);
	printf("%s\n", out2);
}*/
