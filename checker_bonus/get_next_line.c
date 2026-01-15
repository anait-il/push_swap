/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anait-il <anait-il@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:27:00 by anait-il          #+#    #+#             */
/*   Updated: 2026/01/15 15:47:22 by anait-il         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "checker.h"

static char	*_rest_of_the_line(char *stat)
{
	char	*ptr;
	char	*new_stat;

	ptr = stat;
	while (*ptr != '\n' && *ptr)
		ptr++;
	if (*ptr == '\0')
	{
		free(stat);
		stat = NULL;
	}
	else if (*ptr++ == '\n')
	{
		if (*ptr == '\0')
		{
			free(stat);
			stat = NULL;
			return (stat);
		}
		new_stat = ft_strdup(ptr);
		free(stat);
		return (new_stat);
	}
	return (stat);
}

static char	*_new_line(char *stat)
{
	int		i;
	char	*line;

	i = 0;
	while (stat[i] != '\n' && stat[i])
		i++;
	if (stat[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stat[i] && stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	if (stat[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*_free_buffers(int size, char **stat, char *buf)
{
	if (size < 0)
	{
		free(*stat);
		free(buf);
		*stat = NULL;
	}
	else if (size == 0)
		return (free(buf), *stat);
	return (*stat);
}

static char	*_read_the_line(char **stat, char *buf, int fd)
{
	ssize_t		size;

	size = read(fd, buf, BUFFER_SIZE);
	if (size <= 0)
		return (_free_buffers(size, stat, buf));
	buf[size] = '\0';
	*stat = ft_strjoin(*stat, buf);
	if (!*stat)
		return (free(buf), NULL);
	while (!ft_strchr(buf, '\n'))
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == 0)
			return (free(buf), *stat);
		buf[size] = '\0';
		*stat = ft_strjoin(*stat, buf);
		if (!*stat)
			return (free(buf), NULL);
	}
	return (free(buf), *stat);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stat;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
	{
		free(stat);
		stat = NULL;
		return (NULL);
	}
	_read_the_line(&stat, buf, fd);
	if (!stat)
		return (NULL);
	line = _new_line(stat);
	stat = _rest_of_the_line(stat);
	return (line);
}
