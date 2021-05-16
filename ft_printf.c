#include "ft_printf.h"

void	to_init(t_pars *for_start)
{
	for_start->minus = 0;
	for_start->zero = 0;
	for_start->width = 0;
	for_start->precision = -1;
	for_start->type = 0;
}

static int	all_pars(const char *format, int *i, t_pars *flags, va_list ap)
{
	*i = zer_min(format, i, flags);
	*i = width(format, i, flags, ap);
	*i = precision(format, i, flags, ap);
	*i = types(format, i, flags);
	return (*i);
}

static int	my_print(t_pars *flags, va_list ap)
{
	int	length;

	length = 0;
	if (flags->type == '%')
		length = print_percent(flags);
	if (flags->type == 'c')
		length = print_char(va_arg(ap, int), flags);
	if (flags->type == 's')
		length = print_string(va_arg(ap, char *), flags);
	if (flags->type == 'p')
		length = print_pointer(va_arg(ap, unsigned long), flags);
	if (flags->type == 'd' || flags->type == 'i')
		length = print_int(va_arg(ap, int), flags);
	if (flags->type == 'u')
		length = print_unsign_int(va_arg(ap, unsigned int), flags);
	if (flags->type == 'x')
		length = print_x(va_arg(ap, unsigned int), flags);
	if (flags->type == 'X')
		length = print_xx(va_arg(ap, unsigned int), flags);
	return (length);
}

static int	i_read(const char *format, va_list ap)
{
	t_pars	flags;
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			to_init(&flags);
			i = all_pars(format, &i, &flags, ap);
			length += my_print(&flags, ap);
		}
		else
		{
			ft_putchar(format[i]);
			length++;
			i++;
		}
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	va_start(ap, format);
	length = i_read(format, ap);
	va_end(ap);
	return (length);
}
