/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:00:41 by tteng             #+#    #+#             */
/*   Updated: 2025/05/29 11:00:42 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Header Files
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

//Core Function
int		ft_printf(const char *format, ...);
int		ft_check_specifier(char spec, va_list args, int *count);

//Helper Functions
void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putnbl(long n);

//Handler Functions
void	ft_handle_char(va_list args, int *count);
void	ft_handle_str(va_list args, int *count);
void	ft_handle_int(va_list args, int *count);
void	ft_handle_unsigned(va_list args, int *count);
void	ft_handle_hex(char spec, va_list args, int *count);
void	ft_handle_ptr(va_list args, int *count);
void	ft_handle_escape(int *count);

#endif