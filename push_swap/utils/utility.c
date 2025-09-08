/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:03:27 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/24 21:13:43 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int free_stacks, t_stack *stack_a, t_stack *stack_b)
{
	if (free_stacks)
	{
		if (stack_a && stack_a->data)
			free(stack_a->data);
		if (stack_a)
			free(stack_a);
		if (stack_b && stack_b->data)
			free(stack_b->data);
		if (stack_b)
			free(stack_b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

int	is_sorted(t_stack *stack_a)
{
	int	i;

	if (!stack_a || stack_a->length <= 1)
		return (1);
	i = 0;
	while (i < stack_a->length - 1)
	{
		if (stack_a->data[i] > stack_a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
