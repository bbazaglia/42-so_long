#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putptr(size_t ptr);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_puthex(size_t num, char type);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif