/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:03:35 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/12 12:03:49 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_slot_to_buffer(int slot_no, int map_x, int map_y, t_viewport *vp)
{
	t_data			*img;
	t_data			*buf;
	unsigned int	color;
	int				x;
	int				y;

	img = (*vp).images[slot_no];
	buf = (*vp).buffer;
	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
		{
			color = *(unsigned int *)(img->addr + \
					(y * img->ls + x * (img->bpp / 8)));
			if (color != 0xFF000000)
			{
				*(unsigned int *)(buf->addr + ((y + map_y * 64) * buf->ls \
							+ (x + map_x * 64) * (buf->bpp / 8))) = color;
			}
		}
	}
}

void	fill_buffer_bg(t_viewport *vp)
{
	char	*dst;
	int		x;
	int		y;

	y = -1;
	while (++y < (*vp).plan->length * 64)
	{
		x = -1;
		while (++x < (*vp).plan->width * 64)
		{
			dst = (*vp).buffer->addr + (y * (*vp).buffer->ls \
									+ x * (*vp).buffer->bpp / 8);
			*(unsigned int *)dst = 0x00222222;
		}
	}
}

int	frame_render(t_viewport *vp)
{
	int		x;
	int		y;

	fill_buffer_bg(vp);
	y = -1;
	while (++y < (*vp).plan->length)
	{
		x = -1;
		while (++x < (*vp).plan->width)
		{
			draw_slot_to_buffer(SLOT_EMPTY, x, y, vp);
			if ((*vp).plan->map[y][x] == '1')
				draw_slot_to_buffer(SLOT_WALL, x, y, vp);
			else if ((*vp).plan->map[y][x] == 'P')
				draw_slot_to_buffer(SLOT_PLAYER, x, y, vp);
			else if ((*vp).plan->map[y][x] == 'C')
				draw_slot_to_buffer(SLOT_ITEM, x, y, vp);
			else if ((*vp).plan->map[y][x] == 'E')
				draw_slot_to_buffer(SLOT_EXIT, x, y, vp);
		}
	}
	mlx_put_image_to_window((*vp).mlx, (*vp).mlx_win, (*vp).buffer->img, 0, 0);
	return (0);
}
