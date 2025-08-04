/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:04:18 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:04:18 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_puthex(char spec, unsigned int num);
static unsigned int	count_hex(unsigned int num);

void	ft_handle_hex(char spec, va_list args, int *count)
{
	unsigned int	num;
	unsigned int	len;

	num = (unsigned int)va_arg(args, unsigned int);
	ft_puthex(spec, num);
	len = count_hex(num);
	(*count) += len;
}

static void	ft_puthex(char spec, unsigned int num)
{
	unsigned int	digit;

	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (num >= 16)
		ft_puthex(spec, num / 16);
	digit = num % 16;
	if (digit < 10)
		ft_putchar(digit + '0');
	else if (spec == 'X')
		ft_putchar(digit - 10 + 'A');
	else
		ft_putchar(digit - 10 + 'a');
}

static unsigned int	count_hex(unsigned int num)
{
	unsigned int	n;

	n = 1;
	while (num >= 16)
	{
		num /= 16;
		n++;
	}
	return (n);
}
