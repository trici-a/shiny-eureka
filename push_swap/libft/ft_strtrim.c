/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:12:05 by tteng             #+#    #+#             */
/*   Updated: 2025/05/20 10:27:05 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (*s1)
	{
		j = 0;
		while (s1[i] != set[j])
		{
			if (set[j] == 0)
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static size_t	trim_back(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = ft_strlen(s1);
	while (*s1)
	{
		j = ft_strlen(set) - 1;
		while (s1[i - 1] != set[j])
		{
			if (set[j] == 0)
				return (i);
			j--;
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	start = trim_front(s1, set);
	end = trim_back(s1, set);
	len = end - start;
	return (ft_substr(s1, start, len));
}
