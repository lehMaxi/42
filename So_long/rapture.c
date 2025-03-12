/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rapture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:40:38 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/11 11:26:42 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"how_long.h"

void	iconoclast(handler *hand, picture (*stoc)[3][3], int size[2])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size[0])
	{
		while (j < size[1])
		{
			if (stoc[i][j]->addr)
				free(stoc[i][j]->addr);
			if (stoc[i][j]->img)
				mlx_destroy_image(hand->con, stoc[i][j]->img);
			j++;
		}
		j = 0;
		i++;
	}
	return;
}

int	rapture(handler *hand)
{
	iconoclast(hand, &hand->stoc, hand->stoc_size);
	mlx_destroy_window(hand->con, hand->win);
	mlx_destroy_display(hand->con);
	free(hand->con);
	exit(EXIT_SUCCESS);
	return (0);
}	
