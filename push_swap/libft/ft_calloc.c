/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 11:11:05 by tteng             #+#    #+#             */
/*   Updated: 2025/05/20 10:54:16 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp_ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	tmp_ptr = (void *)malloc (total_size);
	if (!tmp_ptr)
		return (NULL);
	ft_memset(tmp_ptr, 0, total_size);
	return (tmp_ptr);
}
