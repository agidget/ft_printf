#include "ft_printf.h"

static int	for_norm1(t_pars *flags)
{
	int	i;
	int	length;

	i = 0;
	length = 1;
	while (++i < flags->width)
	{
		ft_putchar(' ');
		length++;
	}
	return (length);
}

int	print_percent(t_pars *flags)
{
	int		length;
	char	c;

	c = '%';
	length = 1;
	if (flags->width)
	{
		if (flags->minus)
		{
			ft_putchar(c);
			length = for_norm1(flags);
		}
		else
		{
			if (flags->zero)
				length += print_zero(flags->width - 1);
			else
				length = for_norm1(flags);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	return (length);
}
