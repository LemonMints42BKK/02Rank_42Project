/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:29:30 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/21 00:47:33 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <OpenGL/gl3.h>
# include "game_setup.h"
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stddef.h>

# define FD_MAX	5
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_token
{
	char			buff[BUFFER_SIZE];
	struct s_token	*next;
	size_t			nbyte;
}				t_token;

typedef struct s_vars
{
	int		fd;
	int		eof;
	int		fin;
	t_token	*t;
	t_token	*t_last;
	size_t	offset;
	size_t	nl_bytes;
	size_t	tok_len;
}				t_vars;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	char		**map;
	int			width;
	int			length;
	int			collectibles;
	int			total_collec;
	int			at_exit;
	int			is_completed;
	int			moves;
	t_position	player;
	t_position	exit;
}	t_map;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define PATH_EMPTY "textures/0_gress.xpm"
# define PATH_WALL "textures/1_cactus.xpm"
# define PATH_PLAYER "textures/P_black_cat.xpm"
# define PATH_ITEM "textures/C_tuna.xpm"
# define PATH_EXIT "textures/E_door.xpm"
# define SLOT_EMPTY 0
# define SLOT_WALL 1
# define SLOT_PLAYER 2
# define SLOT_ITEM 3
# define SLOT_EXIT 4
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_A_LEFT 0
# define KEY_S_DOWN 1
# define KEY_D_RIGHT 2
# define KEY_W_UP 13
# define ERR_ARG -1
# define ERR_RECT -2
# define ERR_WALL -3
# define ERR_COMP -4
# define ERR_VPATH -5
# define ERR_MEMORY -6

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		w;
	int		l;
	int		bpp;
	int		ls;
	int		ed;
}	t_data;

typedef struct s_viewport
{
	void	*mlx;
	void	*mlx_win;
	t_map	*plan;
	t_data	*buffer;
	t_data	*images[5];
}	t_viewport;

void	print_error(int error_code);
int		first_arg(int argc, char *maps_path);
int		maps_setup(t_map *path, char *maps_path);
int		maps_size(t_map *path, int fd1);
char	*get_next_line(int fd);
int		upload_map(t_map *path, char *maps_path);
int		maps_wall(t_map	*plan);
int		detect_component(t_map *plan);
void	ft_free_map(t_map *plan);
void	assign_zero(t_map *plan);
int		finishable(t_map *plan);
int		frame_render(t_viewport *vp);
int		vp_free_on_exit(t_viewport *vp);
int		viewport_init(t_viewport *vp, t_data *buff, t_data img[5], t_map *plan);
void	free_mlx_image(t_mlx_img_list *img);
void	draw_slot_to_buffer(int slot_no, int map_x, int map_y, t_viewport *vp);
int		move_left(t_map *plan);
int		move_down(t_map *plan);
int		move_right(t_map *plan);
int		move_up(t_map *plan);
void	player_move(t_map *plan, char c, int y, int x);
int		step(t_map *plan, int y, int x);

#endif
