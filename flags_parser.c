#include "ft_printf.h"

int	zer_min(const char *format, int *i, t_pars *flags)
{
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '-')
			flags->minus = 1;
		(*i)++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	return (*i);
}

int	width(const char *format, int *i, t_pars *flags, va_list ap)
{
	if (format[*i] == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
			flags->zero = 0;
		}
		(*i)++;
	}
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		flags->width = flags->width * 10 + format[*i] - '0';
		(*i)++;
	}
	return (*i);
}

static int	prec_norm(const char *format, int *i, t_pars *flags)
{
	int	a;
	int	flag;

	flag = 0;
	a = 0;
	if (format[*i] == '-')
	{
		flags->minus = 1;
		flag = 1;
		(*i)++;
	}
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		a = a * 10 + format[*i] - '0';
		(*i)++;
	}
	if (flag == 0)
		flags->precision = a;
	else if (flag != 0)
	{
		flags->precision = 0;
		flags->width = a;
	}
	return (*i);
}

int	precision(const char *format, int *i, t_pars *flags, va_list ap)
{
	int	a;

	a = 0;
	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			a = va_arg(ap, int);
			if (a >= 0)
				flags->precision = a;
			(*i)++;
		}
		else
			*i = prec_norm(format, i, flags);
	}
	return (*i);
}

int	types(const char *format, int *i, t_pars *flags)
{
	if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p'
		|| format[*i] == 'u' || format[*i] == 'd' || format[*i] == 'i'
		|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
	{
		if (format[*i] == 'c')
			flags->type = 'c';
		if (format[*i] == 's')
			flags->type = 's';
		if (format[*i] == 'p')
			flags->type = 'p';
		if (format[*i] == 'd' || format[*i] == 'i')
			flags->type = 'd';
		if (format[*i] == 'x')
			flags->type = 'x';
		if (format[*i] == 'X')
			flags->type = 'X';
		if (format[*i] == 'u')
			flags->type = 'u';
		if (format[*i] == '%')
			flags->type = '%';
		(*i)++;
	}
	return (*i);
}
