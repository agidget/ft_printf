#include "ft_printf.h"

int	print_string(char *str, t_pars *flags)
{
	int	length;
	int	len_str;

	if (!str)
		str = "(null)";
	length = 0;
	len_str = ft_strlen(str);
	if (flags->precision >= 0)
	{
		if (len_str > flags->precision)
			len_str = flags->precision;
	}
	if (flags->minus)
		ft_putnstr(str, len_str);
	if (flags->width > len_str)
	{
		if (flags->zero)
			length = print_zero(flags->width - len_str);
		else
			length = print_space(flags->width - len_str);
	}
	if (flags->minus == 0)
		ft_putnstr(str, len_str);
	return (length + len_str);
}
