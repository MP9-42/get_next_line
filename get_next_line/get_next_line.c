/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:46:45 by MP9               #+#    #+#             */
/*   Updated: 2025/08/03 14:47:52 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*sorc;

	i = 0;
	dest = (char *)dst;
	sorc = (const char *)src;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}

static char	*make_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (ft_substr(line, 0, i + 1));
	else
		return (ft_strdup(line));
}

static char	*ft_read(int fd, char *buffer, char *line, int *b_read)
{
	char	*temp;

	
}

static void	buffer_clean(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		ft_memcpy(buffer, ft_strchr(buffer, '\n') + 1,
			ft_strlen(ft_strchr(buffer, '\n')));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			b_read;
	char		*line;
	char		*temp;

	b_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_memcpy(buffer, "\0", 1), NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	line = ft_read(fd, buffer, line, &b_read);
	if (!line)
		return (NULL);
	if (ft_strlen(line) == 0 && b_read == 0)
		return (free(line), NULL);
	temp = make_line(line);
	return (buffer_clean(buffer), free(line), temp);
}
