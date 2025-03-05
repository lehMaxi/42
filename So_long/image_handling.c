/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:23:59 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/05 13:34:44 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "how_long.h"

int	imp(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		return (0);
	if (num / 10 > 0)
	{
		i + imp(num / 10);
	}
	return (i);
}

void	complete_address(picture **stoc, int size)
{
	int	i;
	int	j;
	char	*num;
	char	*type;

	i = 0;
	j = 1;
	type = ".png"
	ft_strlcat(stoc[0][0]->addr, "gras_0.png",
			ft_strlen(stoc[0][0]->addr) + 15);
	ft_strlcat(stoc[1][0]->addr, "player_0.png",
			ft_strlen(stoc[1][0]->addr) + 15);
	ft_strlcat(stoc[2][0]->addr, "trees_0.png",
			ft_strlen(stoc[2][0]->addr) + 15);
	while (i < size)
	{
		while (j < size)
		{
			ft_strlcpy(stoc[i][j]->addr,stoc[i][j - 1]->addr, ft_strlen(stoc[i][j - 1]->addr) - (4 + imp(j));
			num = itoa(j);
			ft_strlcat(num, type, 5 + imp(j));
			ft_strlcat(stoc[i][j]->addr, num,ft_strlen(stoc[i][j]->addr) + 5 + imp(j));
			free(num);
			j++;
		}
		j = 1;
		i++;
	}
}

void	image_init(void *con, picture **stoc, int size, int dim)
{
	int	i;

	i = 0;
	while(i < size)
	{
		stoc[i][0]->addr = "./resources/";
		i++;
	}
	complete_address(con, stoc, size)
	//squaer the whole thing, its fine
}
