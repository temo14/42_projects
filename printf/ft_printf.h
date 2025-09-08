/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:48:32 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/19 20:16:30 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_utoa(unsigned int n);
int		ft_putptr_hex(unsigned long n, int is_uppercase);
int		ft_format_hex(va_list args, int is_uppercase);
int		ft_format_pointer(va_list args);
int		ft_format_unsigned(va_list args);
int		ft_format_int(va_list args);
int		ft_format_str(va_list args);
int		ft_format_char(va_list args);
#endif
