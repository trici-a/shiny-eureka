#include "push_swap.h"
#include "libft.h"

//Comment out int main in header file
/* ccc -Iinclude -Ilibft srcs/sort_small.c srcs/swap.c srcs/rev_rotate.c srcs/rotate.c srcs/create_stack.c test_cases/test_sort_three.c libft/libft.a -o test */

void	print_list(t_node *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->value);
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		(*stack) = tmp;
	}
}
int	main()
{
	t_stack stack;

	stack.a = NULL;
	stack.b = NULL;

	//Change these values to the other permutations
	stack.a = new_node(6);
	add_node_back(&stack.a, new_node(5));
	add_node_back(&stack.a, new_node(4));
	/* stack.a->next = new_node(5);
	stack.a->next->next = new_node(4); */
	// Also to prove that add_node_back function is working

	ft_printf("Before Sort:\n");
	print_list(stack.a);

	sort_three(&stack);

	ft_printf("After Sort:\n");
	print_list(stack.a);

	free_stack(&stack.a);
	return (0);
}