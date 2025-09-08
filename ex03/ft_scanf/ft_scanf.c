/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:45:11 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/29 19:36:36 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

int	match_space(FILE *f)
{
	int	c;

	while (1)
	{
		c = fgetc(f);
		if (c == EOF)
			return (-1);
		if (!isspace(c))
		{
			ungetc(c, f);
			break ;
		}
	}
	return (0);
}

int	match_char(FILE *f, char expected)
{
	int	c;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	if (c != expected)
		return (0);
	return (1);
}

int	scan_char(FILE *f, va_list ap)
{
	char	c;
	char	*out;

	c = fgetc(f);
	if (c == EOF)
		return (0);
	out = va_arg(ap, char *);
	*out = (char)c;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int		*out;
	char	c;
	int		result;
	int		sign;

	sign = 1;
	c = fgetc(f);
	while (isspace(c))
		c = fgetc(f);
	if (c == EOF)
		return (0);
	if (c == '-')
	{
		sign = -1;
	}
	while (c = fgetc(f))
	{
		if (c >= '9' || c <= '0')
			break ;
		result = result * 10 + c - '0';
	}
	out = va_arg(ap, int *);
	*out = result * sign;
	return (0);
}

int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	my_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	append_char(char **string, char c)
{
	int		len;
	char	*new_str;

	if (*string == NULL)
	{
		*string = malloc(2);
		(*string)[0] = c;
		(*string)[1] = '\0';
		return ;
	}
	len = my_strlen(*string);
	new_str = malloc(len + 2);
	my_strcpy(new_str, *string);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	free(*string);
	*string = new_str;
}

int	scan_string(FILE *f, va_list ap)
{
	int		c;
	char	*out;
	char	*result;

	result = NULL;
	do
	{
		c = fgetc(f);
		if (c == EOF)
			return (0);
	} while (isspace(c));
	while (c != EOF && !isspace(c))
	{
		append_char(&result, (char)c);
		c = fgetc(f);
	}
	out = va_arg(ap, char *);
	if (result)
	{
		my_strcpy(out, result);
		free(result);
		if (c != EOF)
			ungetc(c, f);
		return (1);
	}
	return (0);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
	case 'c':
		return (scan_char(f, ap));
	case 'd':
		match_space(f);
		return (scan_int(f, ap));
	case 's':
		match_space(f);
		return (scan_string(f, ap));
	case EOF:
		return (-1);
	default:
		return (-1);
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int	nconv;
	int	c;

	nconv = 0;
	c = fgetc(f);
	if (c == EOF)
		return (EOF);
	ungetc(c, f);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break ;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break ;
		}
		else if (match_char(f, *format) != 1)
			break ;
		format++;
	}
	if (ferror(f))
		return (EOF);
	return (nconv);
}

int	ft_scanf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vfscanf(stdin, format, ap);
	return (ret);
}
