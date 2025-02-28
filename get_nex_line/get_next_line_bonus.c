/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:44:41 by mlehmann          #+#    #+#             */
/*   Updated: 2025/02/07 13:12:23 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fill_this_line(int fd, char *next, char *get)
{
	ssize_t	readturn;
	char	*buffer;

	readturn = 1;
	while (readturn > 0)
	{
		readturn = read(fd, get, BUFFER_SIZE);
		if (readturn < 0)
		{
			free(next);
			return (NULL);
		}
		else if (readturn == 0)
			break ;
		get[readturn] = '\0';
		if (!next)
			next = ft_strdup("");
		buffer = next;
		next = ft_strjoin(buffer, get);
		free(buffer);
		if (ft_strchr(next, '\n'))
			break ;
	}
	return (next);
}

char	*hold_the_next_line(char *line)
{
	char	*hold;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	hold = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (!hold)
		return (NULL);
	line[i + 1] = '\0';
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*next[1000];
	char		*line;
	char		*get;

	if (fd >= 1000)
		return (NULL);
	get = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(next[fd]);
		free(get);
		return (NULL);
	}
	if (!get)
		return (NULL);
	line = fill_this_line(fd, next[fd], get);
	free(get);
	next[fd] = hold_the_next_line(line);
	return (line);
}
