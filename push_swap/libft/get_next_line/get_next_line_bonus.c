/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:01:18 by tteng             #+#    #+#             */
/*   Updated: 2025/06/12 14:01:18 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_bytes(int fd, char **buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	if (!(*buffer))
		(*buffer) = ft_strdup("");
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr((*buffer), '\n'))
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		tmp[bytes_read] = '\0';
		*buffer = ft_strjoin(*buffer, tmp);
	}
	free(tmp);
	if (bytes_read == -1 || (bytes_read == 0 && (*buffer)[0] == '\0'))
	{
		free(*buffer);
		return (NULL);
	}
	return (*buffer);
}

static char	*extract_newline(char *buffer)
{
	char	*newline_ptr;

	newline_ptr = ft_strchr(buffer, '\n');
	if (newline_ptr)
		return (ft_substr(buffer, 0, (newline_ptr - buffer) + 1));
	else
		return (ft_strdup(buffer));
}

static char	*remaining_line(char *buffer)
{
	char	*newline_ptr;
	char	*remaining;

	newline_ptr = ft_strchr(buffer, '\n');
	if (!newline_ptr)
	{
		free(buffer);
		return (NULL);
	}
	remaining = ft_strdup(newline_ptr + 1);
	free(buffer);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer[fd] = read_bytes(fd, &buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	newline = extract_newline(buffer[fd]);
	buffer[fd] = remaining_line(buffer[fd]);
	return (newline);
}
