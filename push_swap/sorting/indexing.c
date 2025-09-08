/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:18:52 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/24 21:13:43 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_stack_data_to_array(int len, t_stack *stack_a,
		t_stack *stack_b)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * len);
	if (!arr)
		error(1, stack_a, stack_b);
	i = 0;
	while (i < len)
	{
		arr[i] = stack_a->data[i];
		i++;
	}
	return (arr);
}

static void	reindex_stack(int *sorted_arr, int len, t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len && stack_a->data[i] != sorted_arr[j])
			j++;
		stack_a->data[i] = j;
		i++;
	}
}

void	apply_indexes(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted_arr;
	int	len;

	len = stack_a->length;
	sorted_arr = copy_stack_data_to_array(len, stack_a, stack_b);
	quick_sort(sorted_arr, 0, len - 1);
	reindex_stack(sorted_arr, len, stack_a);
	free(sorted_arr);
}
