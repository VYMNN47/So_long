/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:08:01 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/04 18:01:17 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*find_line(char *left)
{
	int		i;
	char	*line;

	if (!left[0])
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2 * (left[i] == '\n') + 1
				* (left[i] != '\n')));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		line[i] = left[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*next_line(char *left)
{
	int		i;
	char	*str;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	ft_strcpy(str, left + i);
	free(left);
	return (str);
}

static char	*read_byte(int fd, char *left)
{
	char	*buffer;
	int		r_byte;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r_byte = 1;
	while (r_byte != 0 && (!left || !ft_strchr(left, '\n')))
	{
		r_byte = read(fd, buffer, BUFFER_SIZE);
		if (r_byte == -1)
		{
			free(left);
			free(buffer);
			return (NULL);
		}
		buffer[r_byte] = '\0';
		left = strjoin(left, buffer);
	}
	free(buffer);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*left = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = read_byte(fd, left);
	if (left == NULL)
		return (NULL);
	line = find_line(left);
	left = next_line(left);
	return (line);
}
