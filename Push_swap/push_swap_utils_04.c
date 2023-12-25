/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_04.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 08:41:03 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/17 20:54:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
		ft_putchar_fd(*s++, fd);
}

void	check_tab(int *tab, int i)
{
	if (tab[i] == tab[i + 1])
	{
		ft_putstr_fd("Error\n", 2);
		free(tab);
		exit(-1);
	}
}

int	*range(int numbers, char **argv)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (numbers));
	if (!tab)
		return (NULL);
	while (i < numbers)
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < (numbers - 1))
	{
		check_tab(tab, i);
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}
