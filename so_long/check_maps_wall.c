/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:11:54 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/08 10:18:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parallel_horizontal(t_map *plan, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < length)
	{
		if (j == 0 || j == (length - 1))
		{
			i = 0;
			while (i < width)
			{
				if ((*plan).map[j][i] != '1')
				{
					print_error(ERR_WALL);
					return (0);
				}
				i++;
			}
		}
		j++;
	}
	return (1);
}

int	parallel_vertical(t_map *plan, int length, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		if (i == 0 || i == (width - 1))
		{
			j = 0;
			while (j < length)
			{
				if ((*plan).map[j][i] != '1')
				{
					print_error(ERR_WALL);
					return (0);
				}
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	maps_wall(t_map	*plan)
{
	if (!parallel_horizontal(plan, (*plan).length, (*plan).width))
	{
		return (0);
	}
	if (!parallel_vertical(plan, (*plan).length, (*plan).width))
	{
		return (0);
	}
	return (1);
}
