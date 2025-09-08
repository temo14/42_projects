/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:15 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/09 20:11:50 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_int(va_list args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(args, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_format_unsigned(va_list args)
{
	unsigned int	n;
	char			*str;
	int				len;

	n = va_arg(args, unsigned int);
	str = ft_utoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	buffer[11];
	int		i;

	i = 10;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	while (n > 0)
	{
		buffer[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_strdup(&buffer[i]));
}
