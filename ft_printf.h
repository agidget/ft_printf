#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_pars
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	type;
}	t_pars;

void	to_init(t_pars *for_start);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		print_char(char c, t_pars *flags);
int		ft_strlen(const char *str);
void	ft_putnstr(char *str, int num);
void	ft_putnchar(char c, int num);
int		print_string(char *str, t_pars *flags);
int		print_percent(t_pars *flags);
char	*ft_strdup(const char *src);
int		print_pointer(unsigned long adr, t_pars *flags);
char	*ft_itoa(int n);
char	*ft_itoa_uns(unsigned int n);
int		print_zero(int len);
int		print_space(int len);
int		print_pos_int(int n, t_pars *flags);
int		print_neg_int(int n, t_pars *flags);
int		print_int(int n, t_pars *flags);
int		print_unsign_int(unsigned int n, t_pars *flags);
int		print_ox(void);
int		print_x(unsigned int x, t_pars *flags);
int		print_xx(unsigned int x, t_pars *flags);
int		zer_min(const char *format, int *i, t_pars *flags);
int		width(const char *format, int *i, t_pars *flags, va_list ap);
int		precision(const char *format, int *i, t_pars *flags, va_list ap);
int		types(const char *format, int *i, t_pars *flags);
int		num_size(unsigned long lu);

#endif
