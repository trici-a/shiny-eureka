#include "push_swap.h"
#include "libft.h"

/* Comment out int main and free_stack in header file */
/*  ccc -Iinclude -Ilibft srcs/create_stack.c srcs/sort_small.c srcs/swap.c srcs/push.c srcs/rotate.c srcs/rev_rotate.c test_cases/test_sort_five.c libft/libft.a -o test */

void	print_list(t_node *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->value);
		head = head->next;
	}
	ft_printf("NULL\n\n");
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
int main()
{
	t_stack	stack;
	int		stack_size;

	stack.a = NULL;
	stack.b = NULL;

	stack.a = new_node(10);
	add_node_back(&stack.a, new_node(20));
	add_node_back(&stack.a, new_node(40));
	add_node_back(&stack.a, new_node(-20));
	add_node_back(&stack.a, new_node(-160));

	stack_size = stack_count(stack.a);
	assign_index(&stack, stack_size);

	ft_printf("Before sort:\n");
	print_list(stack.a);

	sort_five(&stack);

	ft_printf("\nAfter sort:\n");
	print_list(stack.a);
	
	free_stack(&stack.a);
	return (0);
}