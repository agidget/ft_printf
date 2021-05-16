#include "ft_printf.h"

static int	without_precision(t_pars *flags, int len, int length, char *str)
{
	if (flags->width > len && flags->minus == 0)
	{
		if (!flags->zero)
			length += print_space(flags->width - len);
		else if (flags->width > len)
			length += print_zero(flags->width - len);
	}
	ft_putstr(str);
	if (flags->width > len && flags->minus == 1)
		length += print_space(flags->width - len);
	return (length);
}

static int	with_precision(t_pars *flags, int len, int length, char *str)
{
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > len)
			length += print_space(flags->width - flags->precision);
		else if (flags->width > len)
			length += print_space(flags->width - len);
	}
	if (flags->precision > len)
		length += print_zero(flags->precision - len);
	ft_putstr(str);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > len)
			length += print_space(flags->width - flags->precision);
		else if (flags->width > len)
			length += print_space(flags->width - len);
	}
	return (length);
}

int	print_pos_int(int n, t_pars *flags)
{
	char	*str;
	int		len;
	int		length;

	length = 0;
	if (n == 0 && flags->precision == 0)
	{
		length = print_space(flags->width);
		return (length);
	}
	str = ft_itoa(n);
	len = ft_strlen(str);
	if (flags->precision == -1)
		length = without_precision(flags, len, length, str);
	else if (flags->precision >= 0)
		length = with_precision(flags, len, length, str);
	free(str);
	return (length + len);
}
