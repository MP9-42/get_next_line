/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:47:14 by MP9               #+#    #+#             */
/*   Updated: 2025/07/27 19:19:29 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

size_t	ft_linelen(int fd, char *bbuffer, size_t len)
{
	size_t	i;

	i = 0;
	while ((read(fd, bbuffer, len) != 0)
		|| (ft_strchr(bbuffer, '\n') != '\n'))
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < (int)n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (void *)malloc(sizeof(char) * count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}
