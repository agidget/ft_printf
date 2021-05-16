#include "ft_printf.h"

int	print_int(int n, t_pars *flags)
{
	int	length;

	length = 0;
	if (n >= 0)
		length = print_pos_int(n, flags);
	else
		length = print_neg_int(n, flags);
	return (length);
}
