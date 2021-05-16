#include "ft_printf.h"

static char	*fill_str(int i, unsigned long adr)
{
	char	*str;

	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (--i >= 0)
	{
		if (adr % 16 >= 10)
			str[i] = adr % 16 + 55;
		else
			str[i] = adr % 16 + 48;
		adr /= 16;
	}
	return (str);
}

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

int	print_xx(unsigned int x, t_pars *flags)
{
	char			*str;
	int				length;
	int				i;
	unsigned long	lu;

	length = 0;
	if (x == 0 && flags->precision == 0)
	{
		length = print_space(flags->width);
		return (length);
	}
	lu = (unsigned long)x;
	i = num_size(lu);
	str = fill_str(i, lu);
	if (!str)
		return (0);
	if (flags->precision == -1)
		length = without_precision(flags, i, length, str);
	else if (flags->precision >= 0)
		length = with_precision(flags, i, length, str);
	free(str);
	return (length + i);
}
