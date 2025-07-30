/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:36:49 by MP9               #+#    #+#             */
/*   Updated: 2025/07/30 19:12:52 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (NULL);
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (void *)malloc(sizeof(char) * count * size);
	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		*str = '\0';
		str++;
	}
	return (str);
}


ssize_t	count_mem(int fd)
{
	char	*buffer;
	ssize_t	text;

	text = read(fd, buffer, BUFFER_SIZE);
	while (read(fd, buffer, BUFFER_SIZE) != 0)
		text++;
	return (text);
}

char	*text_to_str(int fd)
{
	char	*str;
	char	*buffer;
	ssize_t	text;
	ssize_t	tlen;

	text = read(fd, buffer, BUFFER_SIZE);
	tlen = count_mem(fd);
	str = (char *)ft_calloc(sizeof(char) * (tlen + 1));
	if (!str)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		ft_strlcpy(str, buffer, BUFFER_SIZE);
		str++;
		text++;
	}
	return (str);
}

int	main()
{
	size_t	m;

	m = open("text.txt", O_RDONLY);
	printf("%s\n", text_to_str(m));
	return (0);
}
