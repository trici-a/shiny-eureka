#include "push_swap.h"
#include "libft.h"

void	print_list(t_node *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->value);
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	print_index(t_node *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->index);
		head = head->next;
	}
	ft_printf("NULL\n");
}

void	free_list(t_node *head)
{
	t_node *tmp;
	
	while (head)
	{
		tmp = head;
		head = head->next;
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
	add_node_back(&stack.a, new_node(-2));
	add_node_back(&stack.a, new_node(20));
	add_node_back(&stack.a, new_node(22));
	/* stack.a->next = new_node(-2);
	stack.a->next->next = new_node(20);
	stack.a->next->next->next = new_node(22); */
	stack_size = stack_count(stack.a);

	ft_printf("Stack a before:\n");
	print_list(stack.a);
	print_index(stack.a);

	ft_printf("Stack a after:\n");
	print_list(stack.a);
	assign_index(&stack, stack_size);
	print_index(stack.a);

	free_list(stack.a);

	return (0);
}