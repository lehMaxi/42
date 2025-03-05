/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:56:36 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/05 13:42:53 by mlehmann         ###   ########.fr       */
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
			       img->img, j * s, i * s);
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

int key_handler(int keycode, handler *hand)
{
	ft_printf("%d\n", keycode);
	if (keycode == 65307)
		rapture(hand);
	return (0);	
}

int	rapture(handler *hand)
{
	mlx_destroy_window(hand->con, hand->win);
	mlx_destroy_display(hand->con);
	free(hand->con);
	exit(EXIT_SUCCESS);
	return (0);
}	

void	is_full(picture **stoc, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while(j < size)
		{
			ft_printf("%s, ", stoc[i][j]->addr);
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
	picture	stoc[3][3];

	s = 64;
	hand.dims[0] = 10;
	hand.dims[1] = 8;
	hand.con = mlx_init();
	hand.win = mlx_new_window(hand.con, hand.dims[0] * s, hand.dims[1] * s, "The gates have opened");
	image_init(hand.con, &&stoc, 3, s);
	is_full(stoc, 3);
//	stoc[0][0].addr = "./resources/gras_1.png";
//	img.img = mlx_png_file_to_image(hand.con, img.addr, &s, &s);
	fill_screen(&hand, &stoc[0][0], s);
	mlx_hook(hand.win, 17, 0, rapture, &hand);
	mlx_hook(hand.win, 2, 1L<<0, key_handler, &hand);
	mlx_loop(hand.con);
	return (0);
}
