/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:03:15 by tteng             #+#    #+#             */
/*   Updated: 2025/05/20 11:54:45 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = -nbl;
	}
	if (nbl >= 10)
	{
		ft_putnbr_fd(nbl / 10, fd);
	}
	ft_putchar_fd((nbl % 10) + '0', fd);
}
