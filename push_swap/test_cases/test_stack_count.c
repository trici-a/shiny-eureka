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

int	main()
{
	t_node	*head;

	head = new_node(10);
	head->next = new_node(-2);
	head->next->next = new_node(20);
	head->next->next->next = new_node(22);

	ft_printf("Stack a:\n");
	print_list(head);
	ft_printf("Size of stack: %d\n", stack_count(head));
	free_list(head);
	return (0);
}
