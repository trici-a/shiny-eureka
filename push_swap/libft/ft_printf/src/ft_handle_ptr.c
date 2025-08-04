/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:00:15 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:00:15 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	count_ptr(void *ptr);
static void		ft_putptr(void *ptr);

void	ft_handle_ptr(va_list args, int *count)
{
	void	*ptr;
	size_t	len;

	ptr = (void *)va_arg(args, void *);
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		(*count) += 5;
		return ;
	}
	ft_putstr("0x");
	(*count) += 2;
	len = count_ptr(ptr);
	ft_putptr(ptr);
	(*count) += len;
}

static size_t	count_ptr(void *ptr)
{
	size_t	n;
	size_t	len;

	n = 1;
	len = (size_t)ptr;
	if (n == 0)
		return (1);
	while (len >= 16)
	{
		len /= 16;
		n++;
	}
	return (n);
}

static void	ft_putptr(void *ptr)
{
	size_t	digit;
	size_t	address;

	address = (size_t)ptr;
	if (address >= 16)
		ft_putptr((void *)(address / 16));
	digit = address % 16;
	if (digit < 10)
		ft_putchar(digit + '0');
	else
		ft_putchar(digit - 10 + 'a');
}
