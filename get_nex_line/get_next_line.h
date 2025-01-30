/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlehmann <mlehmann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:30:21 by mlehmann          #+#    #+#             */
/*   Updated: 2025/01/27 12:30:21 by mlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXTLINE_H
#define GET_NEXTLINE_H
#include <stdlib.h>
#include <fcntl.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char const *s, int c);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif