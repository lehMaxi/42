/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:44:49 by mlehmann          #+#    #+#             */
/*   Updated: 2025/03/05 13:36:21 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOW_LONG_H
# define HOW_LONG_H
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

typedef struct {
		void	*con;
		void	*win;
		int		dims[2];
}			handler;

typedef struct {
		void	*img;
		char	*addr;
		int		bpp;
		int		li_len;
		int		endian;
}			picture;

int	rapture(handler *hand);
int	fill_screen(handler *hand, picture *img, int s);
int	button_handler(int button, int x, int y, handler *hand);
int	key_handler(int keycode, handler *hand);
void	image_init(void *con, picture **stoc, int size, int dim);

#endif
