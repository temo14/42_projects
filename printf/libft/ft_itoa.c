/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:25:52 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/07 19:42:44 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_digits(char *str, long num, size_t i)
{
	while (num)
	{
		str[i--] = '0' + (num % 10);
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;
	size_t	i;

	num = n;
	if (num < 0)
		num = -num;
	len = get_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		i = len - 1;
		fill_digits(str, num, i);
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
