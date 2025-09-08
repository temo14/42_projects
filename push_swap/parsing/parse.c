/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:02:00 by tbaindur          #+#    #+#             */
/*   Updated: 2025/07/24 21:52:20 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate_string(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (!str || !str[0])
		error(1, stack_a, stack_b);
}

static int	get_sign(char *str, int *i, t_stack *stack_a, t_stack *stack_b)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	if (!str[*i] || str[*i] < '0' || str[*i] > '9')
		error(1, stack_a, stack_b);
	return (sign);
}

static long	convert_to_number(char *str, int *i, int sign)
{
	long	num;

	num = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num = num * 10 + (str[*i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && (-1
					* num) < INT_MIN))
			return (-1);
		(*i)++;
	}
	if (str[*i])
		return (-1);
	return (num * sign);
}

int	parse_num(char *str, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		sign;
	long	num;

	validate_string(str, stack_a, stack_b);
	i = 0;
	sign = get_sign(str, &i, stack_a, stack_b);
	num = convert_to_number(str, &i, sign);
	if (num == -1)
		error(1, stack_a, stack_b);
	return ((int)num);
}
