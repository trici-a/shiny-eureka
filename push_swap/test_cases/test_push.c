#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//Push Function
void	print_list(t_node *head)
{
	while (head)
	{
		printf("%d -> ", head->value);
		head = head->next;
	}
	printf("NULL\n");
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
//Test case 1: No node in Stack B
int	main()
{
	t_node	*head;
	t_stack	stack;

	//Create nodes
	head = new_node(1);
	head->next = new_node(2);
	head->next->next = new_node(3);

	// Initialise stacks
	stack.a = head;
	stack.b = NULL;

	printf("Before Pushing from a to b (pb):\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	pb(&stack);

	printf("Before Pushing from b to a (pa):\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	pa(&stack);

	printf("Final Outcome:\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	free_list(stack.a);
	free_list(stack.b);
	return (0);
}

//Test case 2: There are nodes in both stack a and b
/* int	main()
{
	t_node	*head_a;
	t_node	*head_b;
	t_stack	stack;

	//Create nodes
	head_a = new_node(1);
	head_a->next = new_node(2);
	head_a->next->next = new_node(3);

	head_b = new_node(5);
	head_b->next = new_node(10);

	// Initialise stacks
	stack.a = head_a;
	stack.b = head_b;
	stack.move_count = 0;

	printf("Before Pushing from a to b (pb):\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	pb(&stack);

	printf("Before Pushing from b to a (pa):\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	pa(&stack);

	printf("Final Outcome:\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	free_list(stack.a);
	free_list(stack.b);
	return (0);
} */

//Test case 3: There are no nodes in stack a (don't think this will happen(?))
/* int	main()
{
	t_node	*head_b;
	t_stack	stack;

	//Create nodes
	head_b = new_node(1);
	head_b->next = new_node(2);
	head_b->next->next = new_node(3);

	// Initialise stacks
	stack.a = NULL;
	stack.b = head_b;
	stack.move_count = 0;

	printf("Before Pushing from b to a (pa):\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	pa(&stack);

	printf("Before Pushing from a to b (pb):\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	pb(&stack);

	printf("Final Outcome:\n");
	printf("A| ");
	print_list(stack.a);
	printf("B| ");
	print_list(stack.b);

	free_list(stack.a);
	free_list(stack.b);
	return (0);
} */
