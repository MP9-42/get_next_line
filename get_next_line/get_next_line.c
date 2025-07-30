/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MP9 <mikjimen@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:46:45 by MP9               #+#    #+#             */
/*   Updated: 2025/07/30 18:10:30 by MP9              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**fill_words(char **words, const char *s, char c)
{
	size_t	wordi;
	size_t	i;

	wordi = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words[wordi] = one_word(s, c, &i);
			if (!words[wordi])
			{
				while (wordi > 0)
					free(words[--wordi]);
				free(words);
				return (NULL);
			}
			wordi++;
		}
		else
			i++;
	}
	words[wordi] = NULL;
	return (words);
}

char	**ft_split(const char *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!words)
		return (NULL);
	return (fill_words(words, s, c));
}