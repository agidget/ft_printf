#include "ft_printf.h"

int	print_ox(void)
{
	int	len;

	ft_putstr("0x");
	len = 2;
	return (len);
}

int	print_zero(int len)
{
	ft_putnchar('0', len);
	return (len);
}

int	print_space(int len)
{
	ft_putnchar(' ', len);
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnchar(char c, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		write(1, &c, 1);
		i++;
	}
}
