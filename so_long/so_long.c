/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:13:43 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/21 00:12:36 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	print_map(t_map *plan)
{
	int	i;

	i = 0;
	ft_printf("W:%d L:%d 'C':%d\n", (*plan).width, \
	(*plan).length, (*plan).collectibles);
	while ((*plan).map[i] != NULL)
		ft_printf("%s", (*plan).map[i++]);
	ft_printf("\n");
}

void	level_print_info(t_map *p, int key)
{
	if (key == KEY_LEFT || key == KEY_A_LEFT || \
		key == KEY_RIGHT || key == KEY_D_RIGHT || \
		key == KEY_DOWN || key == KEY_S_DOWN || \
		key == KEY_UP || key == KEY_W_UP)
	{
		ft_printf("collected items: %d, at exit: %d, " \
			"finished: %d, moves: %d\n", \
			(*p).total_collec, (*p).at_exit, (*p).is_completed, (*p).moves);
	}
}

void	print_error(int error_code)
{
	if (error_code == ERR_RECT)
		ft_putstr_fd("Error\n Hint: maps/*.ber is not valid\n", 2);
	else if (error_code == ERR_MEMORY)
		ft_putstr_fd("Error\n Hint: Allocated Memory Error\n", 2);
	else if (error_code == ERR_WALL)
		ft_putstr_fd("Error\n Hint: MAP must be surrounded by wall\n", 2);
	else if (error_code == ERR_COMP)
	{
		ft_putstr_fd("Error\n Hint: COMPONENT should be 'P'= 1 'E'= 1\n", 2);
		ft_putstr_fd("             'C' >= 1, '0' and '1' only.\n", 2);
	}
	else if (error_code == ERR_VPATH)
		ft_putstr_fd("Error\n Hint: can't collected all 'C' or enter 'E'\n", 2);
}

int	handler_key(int key, t_viewport *vp)
{
	if (key == KEY_ESC)
	{
		vp_free_on_exit(vp);
		return (0);
	}
	if ((*vp).plan->is_completed == 1)
		return (0);
	if (key == KEY_LEFT || key == KEY_A_LEFT)
		(*vp).plan->moves += move_left((*vp).plan);
	else if (key == KEY_RIGHT || key == KEY_D_RIGHT)
		(*vp).plan->moves += move_right((*vp).plan);
	else if (key == KEY_DOWN || key == KEY_S_DOWN)
		(*vp).plan->moves += move_down((*vp).plan);
	else if (key == KEY_UP || key == KEY_W_UP)
		(*vp).plan->moves += move_up((*vp).plan);
	level_print_info((*vp).plan, key);
	if ((*vp).plan->is_completed == 1)
	{
		ft_printf("----------------------\n~* level completed! *~\n" \
					"----------------------\n");
		exit (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		plan;
	int			status;
	t_viewport	vp;
	t_data		buff;
	t_data		img[5];

	assign_zero(&plan);
	if (first_arg(argc, argv[1]) == ERR_ARG)
		return (1);
	status = maps_setup(&plan, argv[1]);
	if (status == ERR_RECT || status == ERR_MEMORY)
		return (1);
	if (status == ERR_WALL || status == ERR_COMP || status == ERR_VPATH)
	{
		ft_free_map(&plan);
		return (1);
	}
	print_map(&plan);
	if (!viewport_init(&vp, &buff, img, &plan))
		return (1);
	mlx_hook(vp.mlx_win, 17, 0L, vp_free_on_exit, &vp);
	mlx_loop_hook(vp.mlx, frame_render, &vp);
	mlx_key_hook(vp.mlx_win, handler_key, &vp);
	mlx_loop(vp.mlx);
	return (0);
}
