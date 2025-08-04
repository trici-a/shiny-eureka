/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:01:45 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:01:45 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_stack(t_node *head);
void	print_error_exit(t_stack *stack);

void	free_stack(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	print_error_exit(t_stack *stack)
{
	if (stack)
	{
		free_stack(stack->a);
		free_stack(stack->b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
