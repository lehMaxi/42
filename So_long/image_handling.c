/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:23:59 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/12 11:35:14 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "how_long.h"

void	asign_names(picture (*stoc)[3][3])
{
	stoc[0][0]->addr = ft_strjoin(stoc[0][0]->addr, "gras_0.xpm");
	stoc[1][0]->addr = ft_strjoin(stoc[1][0]->addr, "player_0.xpm");
	stoc[2][0]->addr = ft_strjoin(stoc[2][0]->addr, "trees_0.xpm");
//	stoc[3][0]->addr = ft_strjoin(stoc[3][0]->addr, "collectible_0.xpm");
//	stoc[4][0]->addr = ft_strjoin(stoc[4][0]->addr, "entrance_0.xpm");
//	stoc[5][0]->addr = ft_strjoin(stoc[5][0]->addr, "exit_0.xpm");
//	stoc[6][0]->addr = ft_strjoin(stoc[6][0]->addr, "enemy_0.xpm");
}

void	complete_address(picture (*stoc)[3][3], int size[2])
{
	int	i;
	int	j;
	char	*num;
	char	*type;

	i = 0;
	j = 1;
	type = ".xpm";
	while (i < size[0])
	{
		while (j < size[1])
		{
			stoc[i][j]->addr = ft_substr(stoc[i][j - 1]->addr,
				       	0, ft_strlen(stoc[i][j - 1]->addr)
				       	- (4 + imp(j)));
			num = ft_itoa(j);
			num = ft_strjoin(num, type);
			stoc[i][j]->addr = ft_strjoin(stoc[i][j]->addr, num);
			free(num);
			j++;
		}
		j = 1;
		i++;
	}
}

void	image_loader(handler *hand, picture (*stoc)[3][3],
	       	int size[2], int img_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size[0])
	{
		while (j < size[1])
		{
			stoc[i][j]->bpp = 0;
			stoc[i][j]->li_len = 0;
			stoc[i][j]->endian = 0;
			stoc[i][j]->sides = img_size;
			stoc[i][j]->img = NULL;
			stoc[i][j]->img = mlx_xpm_file_to_image(hand->con, stoc[i][j]->addr, &img_size, &img_size);
			img_size = stoc[i][j]->sides;
			j++;
		}
		j = 0;
		i++;
	}
}

void	image_init(handler *hand, picture (*stoc)[3][3], int size[2], int d)
{
	int	i;
	int	img_size;

	img_size = d;
	i = 0;
	while(i < size[0])
	{
		stoc[i][0]->addr = ft_strdup("./resources/");
		i++;
	}
	asign_names(stoc);
	complete_address(stoc, size);
	image_loader(hand, stoc, size, img_size);
	//square the whole thing, its fine
}
