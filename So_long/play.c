/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:56:36 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/11 13:03:09 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "how_long.h"

int	fill_screen(handler *hand, picture *img, int s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(img->img == NULL)
		return(0);
	while (j <= hand->dims[0])
	{
		while (i <= hand->dims[1])
		{
		mlx_put_image_to_window(hand->con, hand->win,
			       hand->stoc[0][0].img, j * s, i * s);
		i++;
		}
	i = 0;
	j++;
	}
	return (0);
}

int	button_handler(int button, int x, int y, handler *hand)
{
	ft_printf("%d at (%d/%d)", button, x ,y);
	if (!button)
			rapture(hand);
	return (0);
}
// 119=W, 97=A, 115=S, 100=D
//void	move(int key, handler *hand)
//{
//	return;
//}

int	key_handler(int keycode, handler *hand)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
		rapture(hand);
//	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
//		move(keycode, hand);
	return (0);	
}

void	is_full(picture (*stoc)[3][3], int size[2])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size[0])
	{
		while(j < size[1])
		{
			ft_printf("%s", stoc[i][j]->addr);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
}

int	main(void)
{
	int		s;
	handler	hand;

	s = 64;
	hand.stoc_size[0] = 3;
	hand.stoc_size[1] = 3;
	hand.dims[0] = 10;
	hand.dims[1] = 8;
	hand.con = mlx_init();
	hand.win = mlx_new_window(hand.con, hand.dims[0] * s, hand.dims[1] * s, "The gates have opened");
	image_init(&hand, &hand.stoc, hand.stoc_size, s);
	is_full(&hand.stoc, hand.stoc_size);
	fill_screen(&hand, &hand.stoc[0][0], s);
	mlx_hook(hand.win, 17, 0, rapture, &hand);
	mlx_hook(hand.win, 2, 1L<<0, key_handler, &hand);
	mlx_loop(hand.con);
	return (0);
}
