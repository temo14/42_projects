/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:28:45 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/09 19:22:43 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_whitespace(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	return (i);
}

static int	handle_overflow(long result, int sign)
{
	if (sign == 1 && result > INT_MAX)
		return (INT_MAX);
	if (sign == -1 && result > (long)INT_MAX + 1)
		return (INT_MIN);
	return ((int)(result * sign));
}

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	size_t	i;

	result = 0;
	sign = 1;
	i = skip_whitespace(nptr);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (handle_overflow(result, sign));
}
