/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tteng <tteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:58:45 by tteng             #+#    #+#             */
/*   Updated: 2025/07/12 16:47:29 by tteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

//Header Functions
# include <unistd.h>
# include <stdlib.h>

//Struct
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

//Check Argument taken in
int		main(int argc, char *argv[]);
void	check_duplicates(t_stack *stack, t_node *head, int arr_value);
void	handle_args(char argv[], t_stack *stack);
void	parse_args(int argc, char *argv[], t_stack *stack);

//Stack Functions
t_node	*new_node(int value);
void	add_node_back(t_node **head, t_node *new);
int		stack_count(t_node *head);
void	assign_index(t_stack *stack, int stack_size);
int		is_sorted(t_node *head);

//Parsing Utility Functions
int		ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);

//Edited Functions
long	ft_atol(char str[], t_stack *stack);
int		is_number(char str[]);

//Operation Helper Functions
void	swap(t_node **head);
void	push(t_node **from, t_node **to);
void	rotate(t_node **head);
void	rev_rotate(t_node **head);

//Operation Functions
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

//Freeing and printing error
void	free_stack(t_node *head);
void	print_error_exit(t_stack *stack);

//Small Sorting Algorithms
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);

//Large Sorting Algorithm
void	rotate_to_top(t_stack *stack, int max_index);
void	rebuild_a_from_b(t_stack *stack);
void	push_chunks_to_b(t_stack *stack, int chunk);
void	sort_large(t_stack *stack, int stack_size);

//Sorting Utilities
int		find_position(t_node *head, int max_index);
int		find_max_index(t_node *head);

#endif