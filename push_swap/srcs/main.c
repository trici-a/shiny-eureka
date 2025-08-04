/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:47:52 by tteng             #+#    #+#             */
/*   Updated: 2025/07/23 10:36:44 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;
	int		size;

	stack.a = NULL;
	stack.b = NULL;
	parse_args(argc, argv, &stack);
	size = stack_count(stack.a);
	assign_index(&stack, size);
	if (!is_sorted(stack.a))
	{
		if (size == 2)
			sa(&stack);
		else if (size == 3)
			sort_three(&stack);
		else if (size == 4)
			sort_four(&stack);
		else if (size == 5)
			sort_five(&stack);
		else
			sort_large(&stack, size);
	}
	free_stack(stack.a);
	free_stack(stack.b);
	return (0);
}
