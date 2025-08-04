/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:00:27 by tteng             #+#    #+#             */
/*   Updated: 2025/07/09 14:00:27 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	check_duplicates(t_stack *stack, t_node *head, int arr_value);
void	parse_args(int argc, char *argv[], t_stack *stack);
void	handle_args(char argv[], t_stack *stack);

void	check_duplicates(t_stack *stack, t_node *head, int arr_value)
{
	while (head)
	{
		if (head->value == arr_value)
			print_error_exit(stack);
		head = head->next;
	}
}

void	handle_args(char argv[], t_stack *stack)
{
	char	**split;
	int		i;
	long	arr_value;

	i = 0;
	split = ft_split(argv, ' ');
	if (!split)
		print_error_exit(stack);
	while (split[i])
	{
		if (!is_number(split[i]))
			print_error_exit(stack);
		arr_value = ft_atol(split[i], stack);
		check_duplicates(stack, stack->a, arr_value);
		add_node_back(&stack->a, new_node(arr_value));
		free(split[i]);
		i++;
	}
	free(split);
}

void	parse_args(int argc, char *argv[], t_stack *stack)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			print_error_exit(stack);
		handle_args(argv[i], stack);
		i++;
	}
}
