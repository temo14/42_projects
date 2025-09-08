/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:25:46 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/09 20:11:50 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_hex(va_list args, int is_uppercase)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putptr_hex(n, is_uppercase));
}
