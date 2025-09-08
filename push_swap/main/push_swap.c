/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:03:56 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/24 21:53:18 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_dup(int *arr, int arr_size, int num)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		if (arr[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	init_and_create_stack(char **string_stack, int size, t_stack **stack_a,
		t_stack *stack_b)
{
	int	i;
	int	num;

	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		error(1, NULL, stack_b);
	(*stack_a)->data = malloc(sizeof(int) * size);
	if (!(*stack_a)->data)
		error(1, *stack_a, stack_b);
	(*stack_a)->length = 0;
	i = 0;
	while (i < size)
	{
		num = parse_num(string_stack[i], *stack_a, stack_b);
		if (is_dup((*stack_a)->data, i, num))
			error(1, *stack_a, stack_b);
		(*stack_a)->data[i] = num;
		(*stack_a)->length++;
		i++;
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->length <= 1 || is_sorted(stack_a))
		return ;
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		error(1, stack_a, NULL);
	stack_b->data = malloc(sizeof(int) * stack_a->length);
	if (!stack_b->data)
		error(1, stack_a, stack_b);
	stack_b->length = 0;
	if (stack_a->length == 2)
		sort_two(stack_a);
	else if (stack_a->length == 3)
		sort_three(stack_a);
	else if (stack_a->length <= 5)
		sort_small(stack_a, stack_b);
	else
	{
		apply_indexes(stack_a, stack_b);
		radix_sort(stack_a, stack_b);
	}
	free_stack(stack_b);
}

static void	handle_args(int argc, char *argv[], char ***args, int *count)
{
	*args = NULL;
	*count = 0;
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		if (!*args)
			error(1, NULL, NULL);
		while ((*args)[*count])
			(*count)++;
	}
	else
	{
		*args = argv + 1;
		*count = argc - 1;
	}
}

int	main(int argc, char *argv[])
{
	char	**args;
	int		count;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	handle_args(argc, argv, &args, &count);
	init_and_create_stack(args, count, &stack_a, stack_b);
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	if (argc == 2)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	return (0);
}
