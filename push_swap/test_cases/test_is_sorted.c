#include "push_swap.h"
#include "libft.h"

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
	t_node *list;
	t_node *list2;

	list = new_node(10);
	add_node_back(&list, new_node(20));
	add_node_back(&list, new_node(30));
	add_node_back(&list, new_node(40));

	list2 = new_node(10);
	add_node_back(&list2, new_node(40));
	add_node_back(&list2, new_node(20));
	add_node_back(&list2, new_node(30));

	ft_printf("%d\n", is_sorted(list));
	ft_printf("%d\n", is_sorted(list2));

	free_list(list);
	free_list(list2);
	return (0);
}
