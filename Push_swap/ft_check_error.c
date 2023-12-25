/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:12:58 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/17 19:26:55 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *strn)
{
	int	i;

	i = 0;
	if ((strn[i] >= '0' && strn[i] <= '9') || strn[i] == '-' || strn[i] == '+')
	{
		if ((strn[i] == '-' || strn[i] == '+') && strn[i + 1] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit (-1);
		}
		i++;
		while (strn[i] != '\0')
		{
			if (!(strn[i] >= '0' && strn[i] <= '9'))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	underflow(long int nbr)
{
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return (1);
	else
		return (0);
}

int	no_sp_no_eof(char *strn)
{
	int	i;

	i = 0;
	if (strn[0] == '\0')
		return (0);
	while (strn[i])
	{
		if (*strn != ' ')
			return (1);
		strn++;
	}
	return (0);
}

int	non_case_error(int numbers, char **data)
{
	char		*strn;
	int			flag;
	int			i;

	i = 0;
	while (i < numbers)
	{
		flag = 0;
		strn = data[i++];
		if (is_integer(strn))
			if (underflow(ft_atoi(strn)))
				flag = 1;
		if (flag == 0)
		{
			ft_putstr_fd("Error\n", 2);
			i = 0;
			while (data[i])
				free(data[i]);
			break ;
		}
	}
	return (flag);
}

void	check_sp_eof(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!no_sp_no_eof(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			exit (-1);
		}
		i++;
	}
}
