/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:00:22 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:00:22 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_unsigned(unsigned int num);

void	ft_handle_unsigned(va_list args, int *count)
{
	unsigned int	num;
	unsigned int	len;

	num = (unsigned int)va_arg(args, unsigned int);
	ft_putnbl(num);
	len = count_unsigned(num);
	(*count) += len;
}

static int	count_unsigned(unsigned int num)
{
	unsigned int	n;

	n = 1;
	while (num >= 10)
	{
		num /= 10;
		n++;
	}
	return (n);
}
