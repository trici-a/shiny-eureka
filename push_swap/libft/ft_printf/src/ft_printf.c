/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:55:50 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:08:02 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	char	spec;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			spec = format[i + 1];
			ft_check_specifier(spec, args, &count);
			i += 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
