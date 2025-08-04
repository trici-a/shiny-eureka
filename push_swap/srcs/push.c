/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:02:35 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:37:16 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(t_node **from, t_node **to);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	pa(t_stack *stack)
{
	push(&stack->b, &stack->a);
	ft_printf("pa\n");
}

void	pb(t_stack *stack)
{
	push(&stack->a, &stack->b);
	ft_printf("pb\n");
}
