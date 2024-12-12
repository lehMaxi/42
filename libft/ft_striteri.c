/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:36:59 by mlehmann          #+#    #+#             */
/*   Updated: 2024/12/04 11:38:08 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*#include <stdio.h>

void function(unsigned int i, char *s)
{
	s[i] += 1;
}
int main(void)
{
	char	stuff[] = "Pathetic z";

	printf("%s", stuff);
	ft_striteri(stuff, function);
	printf("%s", stuff);
	return (0);
}*/
