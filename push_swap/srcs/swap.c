/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:05:18 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:05:19 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_node **head);
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*head) = second;
}

void	sa(t_stack *stack)
{
	swap(&stack->a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(&stack->b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	ft_printf("ss\n");
}
