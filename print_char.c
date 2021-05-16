#include "ft_printf.h"

static int	for_norm(t_pars *flags)
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

int	print_char(char c, t_pars *flags)
{
	int	length;

	length = 1;
	if (flags->width)
	{
		if (flags->minus)
		{
			ft_putchar(c);
			length = for_norm(flags);
		}
		else
		{
			length = for_norm(flags);
			ft_putchar(c);
		}
	}
	else
		ft_putchar(c);
	return (length);
}
