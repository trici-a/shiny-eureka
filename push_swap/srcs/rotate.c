/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:02:59 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:04:55 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate(t_node **head);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	last = *head;
	*head = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack *stack)
{
	rotate(&stack->a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack)
{
	rotate(&stack->b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	ft_printf("rr\n");
}
