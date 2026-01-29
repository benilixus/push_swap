/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-wahm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 17:59:14 by mel-wahm          #+#    #+#             */
/*   Updated: 2025/11/28 20:16:27 by mel-wahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reading_function(char *all, int fd)
{
	char	*buffer;
	int		a;

	a = 1;
	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (a && !(ft_strchr(buffer, '\n')))
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a < 0)
			return (free(all), free(buffer), NULL);
		if (a < BUFFER_SIZE)
			buffer[a] = '\0';
		if (a)
			all = ft_strjoin(all, buffer);
	}
	return (free(buffer), all);
}

char	*extracted_line(char *all)
{
	int		i;
	char	*line;

	i = 0;
	while (all[i] && all[i] != '\n')
		i++;
	line = ft_substr(all, 0, i + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*extracted_from_line(char *all)
{
	int		i;
	char	*leftover;

	i = 0;
	while (all[i] && all[i] != '\n')
		i++;
	if (all[i] == '\n')
		i++;
	if (!all[i])
	{
		free(all);
		return (NULL);
	}
	leftover = ft_substr(all, i, ft_strlen(all + i));
	if (!leftover)
		return (free(all), NULL);
	free(all);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	leftover = reading_function(leftover, fd);
	if (!leftover)
		return (NULL);
	line = extracted_line(leftover);
	leftover = extracted_from_line(leftover);
	return (line);
}
