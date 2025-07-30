/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:47:14 by MP9               #+#    #+#             */
/*   Updated: 2025/07/30 19:07:17 by MP9              ###   ########.fr       */
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

static size_t	count_mem(int fd)
{
	char	*buffer;
	ssize_t	text;

	text = read(fd, buffer, BUFFER_SIZE);
	while (read(fd, buffer, BUFFER_SIZE) != 0)
		text++;
	return (text);
}

static char	*one_word(const char *s, char c, size_t	*i)
{
	char	*word;
	size_t	start;

	start = 0;
	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	word = (char *)malloc(sizeof(char) * (*i - start + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, *i - start + 1);
	return (word);
}

