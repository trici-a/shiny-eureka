/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:06:29 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:06:29 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_str(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str || !count)
		str = "(null)";
	ft_putstr(str);
	(*count) += ft_strlen(str);
}
