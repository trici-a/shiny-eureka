/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:38:54 by tteng             #+#    #+#             */
/*   Updated: 2025/07/23 10:38:54 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	find_max_index(t_node *head);
int	find_position(t_node *head, int max_index);

int	find_max_index(t_node *head)
{
	int	max;

	max = -1;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	return (max);
}

int	find_position(t_node *head, int max_index)
{
	int	pos;

	pos = 0;
	while (head)
	{
		if (head->index == max_index)
			break ;
		pos++;
		head = head->next;
	}
	return (pos);
}
