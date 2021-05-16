#include "ft_printf.h"

static int	num_char(unsigned long int nb)
{
	int	my_rank;

	my_rank = 1;
	if (nb < 0)
	{
		my_rank++;
		nb = -nb;
	}
	while (nb > 10)
	{
		nb /= 10;
		my_rank++;
	}
	if (nb == 10)
		my_rank++;
	return (my_rank);
}

static char	*rev_str(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa_uns(unsigned int n)
{
	char				*str;
	int					i;
	unsigned long int	m;

	m = (unsigned long int)n;
	str = malloc((sizeof(char) * (num_char(m) + 1)));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0"));
	i = 0;
	while (m)
	{
		str[i++] = m % 10 + '0';
		m /= 10;
	}
	str[i] = '\0';
	return (rev_str(str));
}
