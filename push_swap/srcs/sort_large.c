/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:38:46 by tteng             #+#    #+#             */
/*   Updated: 2025/07/23 10:38:47 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate_to_top(t_stack *stack, int max_index);
void	rebuild_a_from_b(t_stack *stack);
void	push_chunks_to_b(t_stack *stack, int chunk);
void	sort_large(t_stack *stack, int stack_size);

void	rotate_to_top(t_stack *stack, int max_index)
{
	int	pos;
	int	size;

	pos = find_position(stack->b, max_index);
	size = stack_count(stack->b);
	if (pos <= (size / 2))
		while (stack->b->index != max_index)
			rb(stack);
	else
		while (stack->b->index != max_index)
			rrb(stack);
}

void	rebuild_a_from_b(t_stack *stack)
{
	int	max;

	while (stack->b)
	{
		max = find_max_index(stack->b);
		rotate_to_top(stack, max);
		pa(stack);
	}
}

void	push_chunks_to_b(t_stack *stack, int chunk)
{
	int	i;

	i = 0;
	while (stack->a)
	{
		if (stack->a->index <= i)
		{
			pb(stack);
			rb(stack);
			i++;
		}
		else if (stack->a->index <= i + chunk)
		{
			pb(stack);
			i++;
		}
		else
			ra(stack);
	}
}

void	sort_large(t_stack *stack, int stack_size)
{
	int	chunk;

	if (stack_size <= 100)
		chunk = 15;
	else
		chunk = 35;
	push_chunks_to_b(stack, chunk);
	rebuild_a_from_b(stack);
}
