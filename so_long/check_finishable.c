/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finishable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:04:46 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/08 10:21:31 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	flood_fill(t_map *plan, int x, int y)
// {
// 	(*plan).map[y][x] = '*';
// 	if (is_fillable_up(plan, x, y))
// 	{
// 		track_item_exit(plan, x, (y - 1));
// 		flood_fill(plan, x,( y - 1));
// 	}
// 	if (is_fillable_down(plan, x, y))
// 	{
// 		track_item_exit(plan, x, (y + 1));
// 		flood_fill(plan, x, (y + 1));
// 	}
// 	if (is_fillable_left(plan, x, y))
// 	{
// 		track_item_exit(plan, (x - 1), y);
// 		flood_fill(plan, (x - 1), y);
// 	}
// 	if (is_fillable_right(plan, x, y))
// 	{
// 		track_item_exit(plan, (x + 1), y);
// 		flood_fill(plan, (x + 1), y);
// 	}
// }
int	fillable(t_map *plan, char **tab, int y, int x)
{
	if (y < 0 || x < 0 || y >= ((*plan).length - 1) || x > (*plan).width)
		return (0);
	if (tab[y][x] == '1')
		return (0);
	else if (tab[y][x] != 1 && tab[y][x] != '*')
		return (1);
	else
		return (0);
}

int	flood_fill(t_map *plan, char **tab, int y, int x)
{
	if (tab[y][x] == 'C')
		(*plan).total_collec += 1;
	if (tab[y][x] == 'E')
		(*plan).at_exit = 1;
	tab[y][x] = '*';
	if (fillable(plan, tab, y - 1, x))
		flood_fill (plan, tab, y - 1, x);
	if (fillable(plan, tab, y + 1, x))
		flood_fill (plan, tab, y + 1, x);
	if (fillable(plan, tab, y, x - 1))
		flood_fill (plan, tab, y, x - 1);
	if (fillable(plan, tab, y, x + 1))
		flood_fill (plan, tab, y, x + 1);
	return (1);
}

int	finishable(t_map *plan)
{
	flood_fill(plan, (*plan).map, (*plan).player.y, (*plan).player.x);
	if ((*plan).collectibles != (*plan).total_collec)
	{
		print_error(ERR_VPATH);
		return (0);
	}
	else if ((*plan).at_exit == 1)
		return (1);
	print_error(ERR_VPATH);
	return (0);
}
