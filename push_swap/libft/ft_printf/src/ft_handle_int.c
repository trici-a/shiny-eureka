/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:00:18 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:00:18 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long num);

void	ft_handle_int(va_list args, int *count)
{
	long	num;
	int		len;

	num = (long)va_arg(args, int);
	ft_putnbl(num);
	len = count_digits(num);
	(*count) += len;
}

static int	count_digits(long num)
{
	long	n;

	n = 1;
	if (num < 0)
	{
		num = -num;
		n++;
	}
	while (num >= 10)
	{
		num /= 10;
		n++;
	}
	return (n);
}
