/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:13:47 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/08 08:13:56 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_print *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	while (*str)
		tab->tl += write(1, str++, 1);
}

void	ft_print_char(t_print *tab)
{
	int	c;

	c = va_arg(tab->args, int);
	tab->tl += write(1, &c, 1);
}

void	ft_print_digit(long long n, char specifier, int *len)
{
	int		base;
	char	*charset;

	if (specifier == 'd' || specifier == 'i' || specifier == 'u')
	{
		charset = "0123456789";
		base = 10;
	}
	if (specifier == 'x')
		charset = "0123456789abcdef";
	if (specifier == 'X')
		charset = "0123456789ABCDEF";
	if (specifier == 'x' || specifier == 'X')
		base = 16;
	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		ft_print_digit(n / base, specifier, len);
	*len += write (1, &charset[n % base], 1);
}

void	ft_print_p(unsigned long n, char specifier, int *len)
{
	unsigned long		base;
	char				*charset;

	charset = "0123456789abcdef";
	base = 16;
	if (n >= base)
		ft_print_p(n / base, specifier, len);
	*len += write (1, &charset[n % base], 1);
}

int	ft_specifier(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 's')
		ft_print_str(tab);
	else if (format[pos] == 'c')
		ft_print_char(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_digit(va_arg(tab->args, int), format[pos], &tab->tl);
	else if (format[pos] == 'u')
		ft_print_digit(va_arg(tab->args, unsigned int), format[pos], &tab->tl);
	else if (format[pos] == 'x')
		ft_print_digit(va_arg(tab->args, unsigned int), format[pos], &tab->tl);
	else if (format[pos] == 'X')
		ft_print_digit(va_arg(tab->args, unsigned int), format[pos], &tab->tl);
	else if (format[pos] == 'p')
	{
		tab->tl += write(1, "0x", 2);
		ft_print_p(va_arg(tab->args, unsigned long), format[pos], &tab->tl);
	}
	else if (format[pos] == '%')
		tab->tl += write(1, "%%", 1);
	return (pos);
}
