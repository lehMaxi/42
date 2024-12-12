/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:32:09 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/09 11:26:17 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntr(char const *s, char c)
{
	int	flag;
	int	i;
	int	count;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		if (flag == 0 && s[i] != c)
		{
			count++;
			flag = 1;
		}
		if (flag == 1 && s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*trim(char *s1, char *s2, char c)
{
	int	s1l;
	int	i;

	i = 0;
	s1l = ft_strlen(s1);
	while (s1[i] == c)
		s1++;
	while (s1[s1l - ft_strlen(s2) - i] == c)
	{
		s1[s1l - ft_strlen(s2) - i] = '\0';
		i++;
	}
	return (s1);
}

static int	fill_arr(char **arr, char *bff, char c, int i)
{
	while (bff[ft_strlen(bff) - 1] == c)
		bff[ft_strlen(bff) - 1] = '\0';
	bff = trim(bff, "\0", c);
	if (cntr(bff, c) > 1)
	{
		arr[i] = ft_strdup(ft_strrchr(bff, c) + 1);
		if (!arr[i])
			return (1);
		bff = trim(bff, ft_strrchr(bff, c), c);
	}
	else
	{
		arr[0] = ft_strdup(bff);
	}
	return (1);
}

static void	break_everything(char **arr, int count)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (i < count)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	char	*bff;

	bff = ft_strdup(s);
	if (!bff)
		return (NULL);
	i = 1;
	arr = (char **)malloc((cntr(s, c) + 1) * (sizeof (char *)));
	if (!arr)
		free(bff);
	if (!arr)
		return (NULL);
	while (i <= cntr(s, c))
	{
		i += fill_arr(arr, bff, c, cntr(s, c) - i);
		if (arr[cntr(s, c) - (i - 1)] == NULL)
			break_everything(arr, cntr(s, c) + 1);
		if (arr[cntr(s, c) - (i - 1)] == NULL)
			return (NULL);
	}
	free(bff);
	arr[cntr(s, c)] = NULL;
	return (arr);
}
/*
#include <stdio.h>

int main(void)
{
	char const	*stuff = " ban nan na nana na ";
	char	c = ' ';
	char	**smolstuff = ft_split(stuff, c);
	int	i = 0;
	while (smolstuff[i])
	{
		printf("%s\n", smolstuff[i]);
		i++;
	}
	break_everything(smolstuff, 5);
	return (0);
}*/
