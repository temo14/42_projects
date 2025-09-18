#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

int	match_space(FILE *f)
{
	int	c;

	c = fgetc(f);
	while (isspace(c))
		c = fgetc(f);
	if (c == EOF)
		return (-1);
	ungetc(c, f);
	return (0);
}

int	match_char(FILE *f, char c)
{
	int	ch;

	ch = fgetc(f);
	if (ch == EOF)
		return (-1);
	if (c == ch)
		return (1);
	return (0);
}

int	scan_char(FILE *f, va_list ap)
{
	int		c;
	char	*ptr;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	ptr = va_arg(ap, char *);
	*ptr = c;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int	c;
	int	sign;
	int	num;
	int	find_digit;
	int	*ptr;

	num = 0;
	sign = 1;
	ptr = va_arg(ap, int *);
	c = fgetc(f);
	if (c == EOF)
		return (-1);
	find_digit = 0;
	if (c == '-')
	{
		sign = -1;
		c = fgetc(f);
	}
	if (c == '+')
		c = fgetc(f);
	while (isdigit(c))
	{
		find_digit = 1;
		num = num * 10 + c - '0';
		c = fgetc(f);
	}
	if (!find_digit)
	{
		if (c != EOF)
			ungetc(c, f);
		return (0);
	}
	ungetc(c, f);
	*ptr = num * sign;
	return (1);
}

int	scan_string(FILE *f, va_list ap)
{
	int		i;
	int		c;
	char	*ptr;

	i = 0;
	ptr = va_arg(ap, char *);
	c = fgetc(f);
	if (c == EOF)
		return (-1);
	while (!isspace(c) && c != EOF)
	{
		ptr[i] = c;
		i++;
		c = fgetc(f);
	}
	if (i == 0 && c == EOF)
		return (-1);
	ptr[i] = '\0';
	ungetc(c, f);
	return (1);
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
	va_end(ap);
	return (ret);
}

// int	main(void)
// {
// 	char	*str;

// 	int a, b;
// 	ft_scanf("%d, %d", &a, &b);
// 	printf("a = %d\nb = %d\n", a, b);
// }

int	main(void)
{
	int a, b;
	char str[100];

	ft_scanf("%d, %d, %s", &a, &b, str);
	printf("a = %d\nb = %d\nstr = %s", a, b, str);
}