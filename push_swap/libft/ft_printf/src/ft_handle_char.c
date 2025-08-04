/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:00:02 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:00:02 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(va_list args, int *count)
{
	char	c;

	c = (char)va_arg(args, int);
	if (!count)
		c = 0;
	ft_putchar(c);
	(*count)++;
}
