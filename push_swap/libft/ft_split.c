/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:31:14 by tteng             #+#    #+#             */
/*   Updated: 2025/05/20 12:24:46 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c);
static size_t	word_len(char const *s, char c);
static char		**allocate(char const *s, char c, size_t count);
static char		**allocate_char(char **new_str, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**res;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	res = allocate(s, c, count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		ft_strlcpy(res[i], s, len + 1);
		s += len;
		i++;
	}
	return (res);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;
	int		in_word;

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

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**allocate(char const *s, char c, size_t count)
{
	char	**new_str;

	new_str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_str)
		return (NULL);
	new_str = allocate_char(new_str, s, c);
	if (!new_str)
	{
		free(new_str);
		return (NULL);
	}
	return (new_str);
}

static char	**allocate_char(char **new_str, char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = word_count(s, c);
	while (i < count)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		new_str[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!new_str[i])
		{
			while (i > 0)
				free(new_str[--i]);
			free(new_str);
			return (NULL);
		}
		s += len;
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
