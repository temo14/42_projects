/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:34:03 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/22 19:34:03 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ints(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = arr[end];
	i = start;
	j = start;
	while (i < end)
	{
		if (arr[i] < pivot)
		{
			swap_ints(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	swap_ints(&arr[j], &arr[end]);
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}
