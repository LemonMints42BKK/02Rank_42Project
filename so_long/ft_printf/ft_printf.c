/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:04:43 by pnopjira          #+#    #+#             */
/*   Updated: 2022/12/21 12:47:22 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_intinialise_tab(t_print *tab)
{
	tab->tl = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	t_print	tab;

	ft_intinialise_tab (&tab);
	va_start(tab.args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_specifier(&tab, format, i + 1);
		else
			len += write (1, &format[i], 1);
	}
	va_end(tab.args);
	len += tab.tl;
	return (len);
}
