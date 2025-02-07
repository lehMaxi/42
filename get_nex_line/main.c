/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwrobles <rwrobles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:23:17 by rwrobles          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:33 by rwrobles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*gnl;
	int		fd;
	int		i;
	int		j;
	
	j = 0;
	if (argc < 2)
	{
		printf("Usage: %s <file1> [file2] ...\n", argv[0]);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			perror("Error opening file");
			return (1);
		}
		printf("\nReading %s:\n", argv[i]);
		while (j < 10)
		{
			gnl = get_next_line(fd);		
			printf("%s", gnl);
			free(gnl);
			j++;
		}
	//	free(gnl);
		close(fd);
		i++;
	}
	return (0);
}

