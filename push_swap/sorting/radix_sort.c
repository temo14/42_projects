/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:01:15 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/24 21:13:43 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	process_bit_pass(int bit_pos, t_stack *stack_a, t_stack *stack_b)
{
	int	j;
	int	size;
	int	bit;

	j = 0;
	size = stack_a->length;
	while (j < size)
	{
		bit = (stack_a->data[0] >> bit_pos) & 1;
		if (bit == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		j++;
	}
	while (stack_b->length > 0)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_bits;

	if (is_sorted(stack_a))
		return ;
	i = 0;
	max_bits = get_max_bits(stack_a->length - 1);
	while (i < max_bits)
	{
		process_bit_pass(i, stack_a, stack_b);
		i++;
	}
}
