#include "push_swap.h"
#include "libft.h"

//Remember to make in the libft directory first, if not there is no libft.a
// ccc -Iinclude -Ilibft test_cases/test_countnodes.c srcs/create_stack.c libft/libft.a -o test
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
	t_node	*head;

	//Create nodes
	head = new_node(1);
	head->next = new_node(2);
	head->next->next = new_node(3);

	ft_printf("Stack a:\n");
	print_list(head);

	ft_printf("\nNumber of nodes in Stack a:\n");
	ft_printf("%d\n", count_nodes(head));

	free_list(head);
	return (0);
}