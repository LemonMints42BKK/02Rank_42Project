/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:27:02 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/21 00:04:14 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maps_setup(t_map *plan, char *maps_path)
{
	int		fd1;

	fd1 = open(maps_path, O_RDONLY);
	if (!maps_size(plan, fd1))
		return (ERR_RECT);
	else if (!upload_map(plan, maps_path))
		return (ERR_MEMORY);
	else if (!maps_wall(plan))
		return (ERR_WALL);
	else if (!detect_component(plan))
		return (ERR_COMP);
	else if (!finishable(plan))
		return (ERR_VPATH);
	else
	{
		ft_free_map(plan);
		assign_zero(plan);
		if (!upload_map(plan, maps_path))
			return (ERR_MEMORY);
		if (!detect_component(plan))
			return (ERR_COMP);
	}
	close(fd1);
	return (0);
}
