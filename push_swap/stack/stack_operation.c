/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:03:05 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/22 19:42:17 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack *stack)
{
	int	temp;

	if (!stack || stack->length < 2)
		return ;
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
}

void	move_top(t_stack *to, t_stack *from)
{
	int	i;
	int	num;

	if (!from || from->length == 0 || !to)
		return ;
	num = from->data[0];
	i = 0;
	while (i < from->length - 1)
	{
		from->data[i] = from->data[i + 1];
		i++;
	}
	from->length--;
	i = to->length;
	while (i > 0)
	{
		to->data[i] = to->data[i - 1];
		i--;
	}
	to->data[0] = num;
	to->length++;
}

void	rotate_up(t_stack *stack)
{
	int	i;
	int	first;

	if (!stack || stack->length < 2)
		return ;
	first = stack->data[0];
	i = 0;
	while (i < stack->length - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = first;
}

void	rotate_down(t_stack *stack)
{
	int	i;
	int	last;

	if (!stack || stack->length < 2)
		return ;
	i = stack->length - 1;
	last = stack->data[i];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = last;
}
