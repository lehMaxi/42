/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:43:09 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 18:45:43 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n == -214783648)
	{
		ft_putstr_fd("-214783648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	else
		num = n;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}
/*
int	main(void)
{
	int n = -214783648;
	int a = -747;
	int b = 0;
	int c = 214783647;

	ft_putnbr_fd(n, 1);
	write(1,"\n", 1);
	ft_putnbr_fd(a, 1);
	write(1,"\n", 1);
	ft_putnbr_fd(b, 1);
	write(1,"\n", 1);
	ft_putnbr_fd(c, 1);
}*/
