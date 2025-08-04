/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:05:36 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:05:36 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);

void	sort_three(t_stack *stack)
{
	int	x;
	int	y;
	int	z;

	if (!stack->a || !(stack->a->next) || !(stack->a->next->next))
		return ;
	x = stack->a->value;
	y = stack->a->next->value;
	z = stack->a->next->next->value;
	if (x > y && x < z && y < z)
		sa(stack);
	else if (x < y && x > z && y > z)
		rra(stack);
	else if (x > y && x > z && y < z)
		ra(stack);
	else if (x < y && x < z && y > z)
	{
		sa(stack);
		ra(stack);
	}
	else if (x > y && x > z && y > z)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_four(t_stack *stack)
{
	while (stack_count(stack->a) > 3)
	{
		if (stack->a->index == 0)
			pb(stack);
		else
			ra(stack);
	}
	sort_three(stack);
	pa(stack);
}

void	sort_five(t_stack *stack)
{
	while (stack_count(stack->a) > 3)
	{
		if (stack->a->index == 0 || stack->a->index == 1)
			pb(stack);
		else
			ra(stack);
	}
	sort_three(stack);
	if (stack->b && stack->b->next && \
(stack->b->index < stack->b->next->index))
		sb(stack);
	while (stack->b)
		pa(stack);
}
