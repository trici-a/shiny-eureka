#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//Ohhh, I don't need to comment out the main in the header if I don't compile together with main.c
// ccc -Iinclude -Ilibft test_cases/test_addnode.c srcs/create_stack.c libft/libft.a -o test

void	print_list(t_node *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->value);
		head = head->next;
	}
	ft_printf("NULL\n");
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

int main()
{
	t_stack	stack;
	t_node	*head;

	//Create nodes
	head = new_node(1);
	head->next = new_node(2);
	head->next->next = new_node(3);

	//Initialise stack
	stack.a = head;
	stack.b = NULL;

	ft_printf("Before adding a node:\n");
	print_list(head);

	add_node_back(&stack.a, new_node(4));

	ft_printf("After adding a node:\n");
	print_list(head);

	free_list(head);
	return (0);
}