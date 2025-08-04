#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

//Reverse rotate

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
	t_node *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	main()
{
	t_node	*head;

	//Create the list
	head = new_node(1);
	head->next = new_node(2);
	head->next->next = new_node(3);

	printf("Before reverse rotation:\n");
	print_list(head);

	rev_rotate(&head);

	printf("After reverse rotation:\n");
	print_list(head);

	free_list(head);
	return (0);
}