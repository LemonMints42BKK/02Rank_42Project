/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:24:28 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/12 20:52:27 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_position(char c, int j, int i, t_map *plan)
{
	if (c == 'P')
	{
		(*plan).player.y = j;
		(*plan).player.x = i;
	}
	if (c == 'E')
	{
		(*plan).exit.y = j;
		(*plan).exit.x = i;
	}
	return (1);
}

int	count_component(t_map *plan, int *count_p, int *count_e, int *count_c)
{
	int	j;
	int	i;

	j = 1;
	i = 1;
	while (j < ((*plan).length - 1))
	{
		i = 1;
		while (i < ((*plan).width - 1))
		{
			if ((*plan).map[j][i] == 'P')
				*count_p += set_position('P', j, i, plan);
			else if ((*plan).map[j][i] == 'E')
				*count_e += set_position('E', j, i, plan);
			else if ((*plan).map[j][i] == 'C')
				*count_c += 1;
			else if ((*plan).map[j][i] != '0' && (*plan).map[j][i] != '1')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	detect_component(t_map *plan)
{
	int	count_p;
	int	count_e;
	int	count_c;

	count_p = 0;
	count_e = 0;
	count_c = 0;
	if (!count_component(plan, &count_p, &count_e, &count_c))
	{
		print_error(ERR_COMP);
		return (0);
	}
	(*plan).collectibles = count_c;
	if (count_p > 1 || count_p < 1 || count_e > 1 || count_e < 1)
	{
		print_error(ERR_COMP);
		return (0);
	}
	else if (count_c < 1)
	{
		print_error(ERR_COMP);
		return (0);
	}
	return (1);
}
