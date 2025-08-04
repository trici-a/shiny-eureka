/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:02:38 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:02:57 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rev_rotate(t_node **head);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rev_rotate(t_node **head)
{
	t_node	*prev;
	t_node	*curr;

	if (!*head || !(*head)->next)
		return ;
	prev = NULL;
	curr = *head;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *head;
	*head = curr;
}

void	rra(t_stack *stack)
{
	rev_rotate(&stack->a);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack)
{
	rev_rotate(&stack->b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
}
