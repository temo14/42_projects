/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:18:43 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/09 20:11:23 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_format_char(args));
	else if (c == 's')
		return (ft_format_str(args));
	else if (c == 'p')
		return (ft_format_pointer(args));
	else if (c == 'd' || c == 'i')
		return (ft_format_int(args));
	else if (c == 'u')
		return (ft_format_unsigned(args));
	else if (c == 'x')
		return (ft_format_hex(args, 0));
	else if (c == 'X')
		return (ft_format_hex(args, 1));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		printed;

	printed = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed += ft_handle_format(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}
