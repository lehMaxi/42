/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:44:41 by mlehmann          #+#    #+#             */
/*   Updated: 2025/02/04 13:27:28 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			return(NULL);
		}
		else if (readturn == 0)
			break;
		get[readturn] = '\0';
		if (!next)
			next = ft_strdup("");
		buffer = next;
		next = ft_strjoin(buffer, get);
		free(buffer);
		if (ft_strchr(next, '\n'))
			break;
	}
	return (next);
}

char	*hold_the_next_line(char *line)
{
	char	*hold;
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return(NULL);
	hold = ft_strdup(ft_strchr(line, '\n') + 1);
	if (!hold)
		return(NULL);
	line[i + 1] = '\0';
	return (hold);
}

char    *get_next_line(int fd)
{
    static char *next;
    char        *line;
    char        *get;

    get = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(next);
        free(get);
        return (NULL);
    }
	if (!get)
		return(NULL);
	line = fill_this_line(fd, next, get);
	free(get);
	next = hold_the_next_line(line);
	return(line);
}
