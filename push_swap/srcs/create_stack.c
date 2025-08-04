/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:00:54 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:00:54 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_node	*new_node(int value);
void	add_node_back(t_node **head, t_node *new);
int		stack_count(t_node *head);
void	assign_index(t_stack *stack, int stack_size);
int		is_sorted(t_node *head);

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	add_node_back(t_node **head, t_node *new)
{
	t_node	*tmp;

	if (!head || !new)
		return ;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int	stack_count(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	assign_index(t_stack *stack, int stack_size)
{
	t_node	*curr;
	t_node	*min;
	int		index;

	index = 0;
	while (index < stack_size)
	{
		curr = stack->a;
		min = NULL;
		while (curr)
		{
			if (curr->index == -1 && \
(min == NULL || curr->value < min->value))
				min = curr;
			curr = curr->next;
		}
		if (min)
		{
			min->index = index;
			index++;
		}
	}
}

int	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}
