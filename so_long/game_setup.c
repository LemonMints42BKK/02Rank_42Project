/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:32 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/18 15:31:32 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mlx_image(t_mlx_img_list *img)
{
	free(img->buffer);
	free(img);
}

static void	viewport_init_p2(t_viewport *vp, t_data *b, t_data i[5], t_map *p)
{
	(*b).img = mlx_new_image((*vp).mlx, (*p).width * 64, (*p).length * 64);
	(*b).addr = mlx_get_data_addr((*b).img, &b->bpp, &b->ls, &b->ed);
	i[0].img = mlx_xpm_file_to_image((*vp).mlx, PATH_EMPTY, &i[0].w, &i[0].l);
	i[1].img = mlx_xpm_file_to_image((*vp).mlx, PATH_WALL, &i[1].w, &i[1].l);
	i[2].img = mlx_xpm_file_to_image((*vp).mlx, PATH_PLAYER, &i[2].w, &i[2].l);
	i[3].img = mlx_xpm_file_to_image((*vp).mlx, PATH_ITEM, &i[3].w, &i[3].l);
	i[4].img = mlx_xpm_file_to_image((*vp).mlx, PATH_EXIT, &i[4].w, &i[4].l);
	i[0].addr = mlx_get_data_addr(i[0].img, &i[0].bpp, &i[0].ls, &i[0].ed);
	i[1].addr = mlx_get_data_addr(i[1].img, &i[1].bpp, &i[1].ls, &i[1].ed);
	i[2].addr = mlx_get_data_addr(i[2].img, &i[2].bpp, &i[2].ls, &i[2].ed);
	i[3].addr = mlx_get_data_addr(i[3].img, &i[3].bpp, &i[3].ls, &i[3].ed);
	i[4].addr = mlx_get_data_addr(i[4].img, &i[4].bpp, &i[4].ls, &i[4].ed);
	vp->buffer = b;
	vp->images[SLOT_EMPTY] = &i[0];
	vp->images[SLOT_WALL] = &i[1];
	vp->images[SLOT_PLAYER] = &i[2];
	vp->images[SLOT_ITEM] = &i[3];
	vp->images[SLOT_EXIT] = &i[4];
	vp->plan = p;
}

int	viewport_init(t_viewport *vp, t_data *buff, t_data img[5], t_map *plan)
{
	(*vp).mlx = mlx_init();
	if ((*vp).mlx == NULL)
	{
		ft_putstr_fd("Error\n Hint: unable to malloc MLX objects", 2);
		ft_free_map(plan);
		return (0);
	}
	vp->mlx_win = mlx_new_window(vp->mlx, plan->width * 64, \
	plan->length * 64, "so_long");
	if ((*vp).mlx_win == NULL)
	{
		ft_putstr_fd("Error\n Hint: unable to malloc MLX objects", 2);
		ft_free_map(plan);
		if (((t_mlx_ptr *)(*vp).mlx)->font != NULL)
			free_mlx_image(((t_mlx_ptr *)(*vp).mlx)->font);
		free((t_mlx_ptr *)(*vp).mlx);
		return (0);
	}
	viewport_init_p2(vp, buff, img, plan);
	return (1);
}
