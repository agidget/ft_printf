#include "ft_printf.h"

static int	without_precision(t_pars *flags, int len, int length, char *str)
{
	if ((flags->width > len + 1) && flags->minus == 0)
	{
		if (!flags->zero && (flags->width - len - 1) > 0)
		{
			length += print_space(flags->width - len - 1);
			ft_putchar('-');
		}
		else if ((flags->width - len - 1) > 0)
		{
			ft_putchar('-');
			length += print_zero(flags->width - len - 1);
		}
		ft_putstr(str);
	}
	else
	{
		ft_putchar('-');
		ft_putstr(str);
		if (flags->width > len && flags->minus == 1
			&& (flags->width - len - 1) > 0)
			length += print_space(flags->width - len - 1);
	}
	return (length + 1);
}

static int	with_precision(t_pars *flags, int len, int length, char *str)
{
	if (flags->width > flags->precision && flags->minus == 0)
	{
		if (flags->precision > len)
			length += print_space(flags->width - flags->precision - 1);
		else if (flags->width - len - 1 > 0)
			length += print_space(flags->width - len - 1);
	}
	ft_putchar('-');
	if (flags->precision > len)
		length += print_zero(flags->precision - len);
	ft_putstr(str);
	if (flags->width > flags->precision && flags->minus == 1)
	{
		if (flags->precision > len)
			length += print_space(flags->width - flags->precision - 1);
		else if (flags->width - len - 1 > 0)
			length += print_space(flags->width - len - 1);
	}
	return (length + 1);
}

int	print_neg_int(int n, t_pars *flags)
{
	char			*str;
	int				len;
	int				length;
	unsigned int	m;

	length = 0;
	m = (unsigned int)-n;
	str = ft_itoa_uns(m);
	len = ft_strlen(str);
	if (flags->precision == -1)
		length = without_precision(flags, len, length, str);
	else if (flags->precision >= 0)
		length = with_precision(flags, len, length, str);
	free(str);
	return (length + len);
}
