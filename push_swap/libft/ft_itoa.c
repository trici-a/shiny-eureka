/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:40:58 by tteng             #+#    #+#             */
/*   Updated: 2025/05/20 11:03:36 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n);
static void	fill(char *res, long nl, int len);

char	*ft_itoa(int n)
{
	char	*res;
	long	nl;
	int		len;

	nl = n;
	len = int_len(nl);
	res = (char *)malloc(sizeof(char) * (int_len(nl) + 1));
	if (!res)
		return (NULL);
	if (nl == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	fill(res, nl, len);
	return (res);
}

static int	int_len(long nl)
{
	size_t	count;

	count = 1;
	if (nl < 0)
	{
		nl = -nl;
		count++;
	}
	while (nl >= 10)
	{
		nl /= 10;
		count++;
	}
	return (count);
}

static void	fill(char *res, long nl, int len)
{
	int	i;

	i = 0;
	if (nl < 0)
	{
		res[0] = '-';
		nl = -nl;
		i++;
	}
	res[len] = '\0';
	while (--len >= i)
	{
		res[len] = (nl % 10) + '0';
		nl /= 10;
	}
}
