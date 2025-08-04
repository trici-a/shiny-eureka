/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:59:58 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 10:59:58 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(char spec, va_list args, int *count)
{
	if (spec == 'c')
		ft_handle_char(args, count);
	else if (spec == 's')
		ft_handle_str(args, count);
	else if (spec == 'd' || spec == 'i')
		ft_handle_int(args, count);
	else if (spec == 'u')
		ft_handle_unsigned(args, count);
	else if (spec == 'x' || spec == 'X')
		ft_handle_hex(spec, args, count);
	else if (spec == 'p')
		ft_handle_ptr(args, count);
	else if (spec == '%')
		ft_handle_escape(count);
	return (0);
}
