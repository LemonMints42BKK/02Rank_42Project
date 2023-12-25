/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:21 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/18 15:43:18 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SETUP_H
# define GAME_SETUP_H

typedef float			t_glfoat;
typedef unsigned int	t_gluint;

typedef struct s_mlx_img_list
{
	int						width;
	int						length;
	char					*buffer;
	t_glfoat				vertexes[8];
	struct s_mlx_img_list	*next;
}	t_mlx_img_list;

typedef struct s_mlx_img_ctx
{
	t_gluint				texture;
	t_gluint				vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}	t_mlx_img_ctx;

typedef struct s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}	t_mlx_win_list;

typedef struct s_mlx_ptr
{
	void			*appid;
	t_mlx_win_list	*win_list;
	t_mlx_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*lop_timer;
	t_mlx_img_list	*font;
	int				main_loop_active;
}	t_mlx_ptr;

#endif
