/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:29 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/09 20:38:35 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_pointer(va_list args)
{
	void	*ptr;
	int		count;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count = 2;
	count += ft_putptr_hex((unsigned long)ptr, 0);
	return (count);
}

int	ft_putptr_hex(unsigned long n, int is_uppercase)
{
	const char	*hex;
	int			count;

	count = 0;
	if (is_uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_putptr_hex(n / 16, is_uppercase);
	ft_putchar_fd(hex[n % 16], 1);
	return (count + 1);
}
