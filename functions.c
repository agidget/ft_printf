#include "ft_printf.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnstr(char *str, int num)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i < num)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = malloc(ft_strlen((char *)src) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, (char *)src);
	return (dest);
}
