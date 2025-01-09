/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:43:13 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/09 13:34:42 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);//writes input and calls the rest
int	ft_putchar(int c);//writes a char
int	ft_putstring(char *s);// writes a string
int	ft_putdecimal(int i, unsigned int u);// writes an int signed or not
int	ft_putpointer(void *p);// writes the adress of a pointer in hexadecimal
int	ft_puthex(unsigned int n, char c);// puts a hexadecimal on the terminal
#endif
