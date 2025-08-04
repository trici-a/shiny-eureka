
//add this before int main
/* void	print_list(t_node *head)
{
	while (head)
	{
		ft_printf("%d -> ", head->index);
		head = head->next;
	}
	ft_printf("NULL\n");
} */

// this is to put into int main to prove that the sorting is correct visually
//add this after if(!is_sorted(stack.a)){}
	// print_list(stack.a);

// this is to print in between the sorting process in sort large

/* void	print_list(t_node *stack)
{
	t_node *tmp;
	tmp = stack;
	ft_printf("Index:\n");
	while (stack)
	{
		ft_printf("%d -> ", stack->index);
		stack = stack->next;
	}
	ft_printf("NULL\n");
	ft_printf("Values:\n");
	while (tmp)
	{
		ft_printf("%d -> ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
} */

// to add to sort_large
	//print_list(stack->a);
	//print_list(stack->b);

// to add to push_chunks_to_b
	//print_list(stack->b);

