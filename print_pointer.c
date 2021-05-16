#include "ft_printf.h"

static char	*fill_str(char *str, int i, unsigned long adr)
{
	str[i] = '\0';
	while (--i >= 0)
	{
		if (adr % 16 >= 10)
			str[i] = adr % 16 + 87;
		else
			str[i] = adr % 16 + 48;
		adr /= 16;
	}
	return (str);
}

static int	if_precision(t_pars *flags, int length, char *str)
{
	if ((flags->width > flags->precision) && (flags->precision > length))
	{
		length += print_space(flags->width - flags->precision - 2);
		length += print_ox();
		length += print_zero(flags->precision - length + 4);
		ft_putstr(str);
	}
	if (flags->precision > length)
	{
		length += print_ox();
		length += print_zero(flags->precision - length + 2);
		ft_putstr(str);
	}
	return (length);
}

static int	if_width(t_pars *flags, int length, char *str)
{
	if (flags->width > length)
	{
		if (!flags->minus && (flags->width - length > 2))
		{
			length += print_space(flags->width - length - 2);
			length += print_ox();
			ft_putstr(str);
		}
		else
		{
			length += print_ox();
			ft_putstr(str);
			if (flags->width - length > 0)
				length += print_space(flags->width - length);
		}
	}
	else
	{
		length += print_ox();
		ft_putstr(str);
	}
	return (length);
}

static int	pointer_norm(t_pars *flags, int length, char *str)
{
	if (flags->precision > length)
		length = if_precision(flags, length, str);
	else if (flags->width)
		length = if_width(flags, length, str);
	else if (!flags->width)
	{
		length += print_ox();
		ft_putstr(str);
	}
	return (length);
}

int	print_pointer(unsigned long adr, t_pars *flags)
{
	char	*str;
	int		length;
	int		i;

	length = 1;
	if (adr == 0 && flags->precision == -1)
		str = ft_strdup("0");
	else
	{
		if (adr != 0)
			i = num_size(adr);
		else
			i = 0;
		length = i;
		str = malloc(sizeof(char) * (i + 1));
		if (!str)
			return (0);
		str = fill_str(str, i, adr);
	}
	length = pointer_norm(flags, length, str);
	free(str);
	return (length);
}
