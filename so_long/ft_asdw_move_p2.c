/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asdw_move_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:21:15 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/12 22:48:56 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	at_path(t_map *plan, int y, int x)
{
	if ((*plan).map[(*plan).player.y][(*plan).player.x] == 'E')
		player_move(plan, 'E', y, x);
	else
		player_move(plan, '0', y, x);
}

void	at_exit(t_map *plan, int y, int x)
{
	player_move(plan, '0', y, x);
	(*plan).at_exit = 1;
	if ((*plan).total_collec == (*plan).collectibles)
		(*plan).is_completed = 1;
	(*plan).map[(*plan).player.y][(*plan).player.x] = 'E';
}

int	step(t_map *plan, int y, int x)
{
	if ((*plan).map[y][x] != '1')
	{
		(*plan).at_exit = 0;
		if ((*plan).map[y][x] == 'C')
		{
			(*plan).total_collec += 1;
			at_path(plan, y, x);
		}
		else if ((*plan).map[y][x] == 'E')
			at_exit(plan, y, x);
		else
			at_path(plan, y, x);
		return (1);
	}
	else
		return (0);
}
