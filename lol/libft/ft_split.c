/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:34 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/10 16:59:55 by rtari-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static int	word_length(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**free_res(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;
	int		word_count;
	int		len;

	i = 0;
	word_count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!res)
		return (NULL);
	while (i < word_count)
	{
		while (*s == c)
			s++;
		len = word_length(s, c);
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!res[i])
			return (free_res(res, i));
		ft_strlcpy(res[i], s, len + 1);
		s += len;
		i++;
	}
	res[i] = NULL;
	return (res);
}
