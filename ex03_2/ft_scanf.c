#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>

int	match_space(FILE *f)
{
	int	c;

	while (1)
	{
		c = fgetc(f);
		if (!isspace(c))
			break ;
	}
	if (c != EOF)
		ungetc(c, f);
	return (0);
}

int	match_char(FILE *f, char c)
{
	int	ch;

	ch = fgetc(f);
	if (ch == c)
		return (1);
	if (ch != EOF)
		ungetc(ch, f);
	return (0);
}

int	scan_char(FILE *f, va_list ap)
{
	int	*p;
	int	c;

	p = va_arg(ap, int *);
	c = fgetc(f);
	if (c = EOF)
		return (0);
	p = c;
	return (1);
}

int	scan_int(FILE *f, va_list ap)
{
	int	c;
	int	*p;
	int	sign;
	int	got_digit;
	int	val;

	sign = 1;
	got_digit = 0;
	c = fgetc(f);
	p = va_arg(ap, int *);
	if (c == '-')
	{
		sign = -1;
		c = fgetc(f);
	}
	while (isdigit(c))
	{
		got_digit = 1;
		val = val * 10 + c - '0';
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (!got_digit)
		return (0);
	*p = val * sign;
	return (1);
}

int	scan_string(FILE *f, va_list ap)
{
	char	*s;
	int		c;

	s = va_arg(ap, char *);
	c = fgetc(f);
	if (c == EOF || isspace(c))
		return (0);
	while (c != EOF && !isspace(c))
	{
		*s++ = c;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	*s = '\0';
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
	va_list ap;
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return (ret);
}