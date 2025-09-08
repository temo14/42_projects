/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:18:12 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/24 21:13:43 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a->data[0] > stack_a->data[1])
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->data[0];
	b = stack_a->data[1];
	c = stack_a->data[2];
	if (is_sorted(stack_a))
		return ;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

int	find_min_index(t_stack *stack_a)
{
	int	i;
	int	min_idx;
	int	min_val;

	i = 0;
	min_idx = 0;
	min_val = stack_a->data[0];
	while (i < stack_a->length)
	{
		if (stack_a->data[i] < min_val)
		{
			min_val = stack_a->data[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	move_min_to_top(t_stack *stack_a)
{
	int	min_idx;
	int	len;

	min_idx = find_min_index(stack_a);
	len = stack_a->length;
	if (min_idx <= len / 2)
	{
		while (min_idx > 0)
		{
			ra(stack_a);
			min_idx--;
		}
	}
	else
	{
		while (min_idx < len)
		{
			rra(stack_a);
			min_idx++;
		}
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->length > 3)
	{
		move_min_to_top(stack_a);
		pb(stack_a, stack_b);
	}
	if (stack_a->length == 2)
		sort_two(stack_a);
	else if (stack_a->length == 3)
		sort_three(stack_a);
	while (stack_b->length > 0)
		pa(stack_a, stack_b);
}
