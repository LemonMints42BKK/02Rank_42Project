/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:02:48 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/18 15:33:50 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	vp_free_on_exit(t_viewport *vp)
{
	ft_printf("Exit, thanks for playing!\n");
	ft_free_map((*vp).plan);
	free_mlx_image((*vp).images[SLOT_EXIT]->img);
	free_mlx_image((*vp).images[SLOT_ITEM]->img);
	free_mlx_image((*vp).images[SLOT_PLAYER]->img);
	free_mlx_image((*vp).images[SLOT_WALL]->img);
	free_mlx_image((*vp).images[SLOT_EMPTY]->img);
	free_mlx_image((*vp).buffer->img);
	free_mlx_image(((t_mlx_ptr *)(*vp).mlx)->font);
	free(((t_mlx_ptr *)(*vp).mlx)->win_list->img_list);
	free(((t_mlx_ptr *)(*vp).mlx)->win_list);
	free((t_mlx_ptr *)(*vp).mlx);
	exit(0);
	return (0);
}

void	assign_zero(t_map *plan)
{
	(*plan).collectibles = 0;
	(*plan).total_collec = 0;
	(*plan).at_exit = 0;
	(*plan).is_completed = 0;
	(*plan).moves = 0;
	(*plan).player.x = 0;
	(*plan).player.y = 0;
	(*plan).exit.x = 0;
	(*plan).exit.y = 0;
}

void	ft_free_map(t_map *plan)
{
	int	j;

	j = 0;
	while (j < (*plan).length)
	{
		free((*plan).map[j]);
		(*plan).map[j] = NULL;
		j++;
	}
	free((*plan).map);
	(*plan).map = NULL;
}
