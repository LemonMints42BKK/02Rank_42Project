/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asdw_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:37:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/12 22:47:28 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_map *plan, char c, int y, int x)
{
	(*plan).map[(*plan).player.y][(*plan).player.x] = c;
	(*plan).map[y][x] = 'P';
	(*plan).player.x = x;
	(*plan).player.y = y;
}

int	move_left(t_map *plan)
{
	int	y;
	int	x;

	y = (*plan).player.y;
	x = (*plan).player.x - 1;
	if ((y > (*plan).length) || (y < 0) || (x > (*plan).width) || (y < 0))
		return (-1);
	return (step(plan, y, x));
}

int	move_down(t_map *plan)
{
	int	y;
	int	x;

	y = (*plan).player.y + 1;
	x = (*plan).player.x;
	if ((y > (*plan).length) || (y < 0) || (x > (*plan).width) || (y < 0))
		return (-1);
	return (step(plan, y, x));
}

int	move_right(t_map *plan)
{
	int	y;
	int	x;

	y = (*plan).player.y;
	x = (*plan).player.x + 1;
	if ((y > (*plan).length) || (y < 0) || (x > (*plan).width) || (y < 0))
		return (-1);
	return (step(plan, y, x));
}

int	move_up(t_map *plan)
{
	int	y;
	int	x;

	y = (*plan).player.y - 1;
	x = (*plan).player.x;
	if ((y > (*plan).length) || (y < 0) || (x > (*plan).width) || (y < 0))
		return (-1);
	return (step(plan, y, x));
}
