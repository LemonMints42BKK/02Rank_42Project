# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 11:19:47 by pnopjira          #+#    #+#              #
#    Updated: 2023/04/18 15:31:06 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
M		:= make

SRC		:= so_long.c\
			check_first_arg.c\
			check_maps_setup.c\
			check_maps_size.c\
			ft_get_next_line.c\
			check_unload_map.c\
			check_maps_wall.c\
			check_components.c\
			ft_free_map.c\
			check_finishable.c\
			game_setup.c\
			ft_frame_render.c\
			ft_asdw_move.c\
			ft_asdw_move_p2.c\

LIBFT	:= ./libft/libft.a
PRINTF 	:= ./ft_printf/libftprintf.a
MLX		:= ./mlx/libmlx.a

#all: sub-make $(LIBFT) $(PRINTF) $(MLX) $(NAME)
all: sub-make $(NAME)

$(NAME): $(LIBFT) $(SRC) sub-make
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -L./libft -lft -L./ft_printf -lftprintf -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

sub-make:
	$(M) -C libft
	$(M) -C ft_printf
	$(M) -C mlx

clean:
	@rm -rf *.o
	@$(M) clean -C libft
	@$(M) clean -C ft_printf
	@$(M) clean -C mlx

fclean: clean
	@$(M) fclean -C libft
	@$(M) fclean -C ft_printf
	@$(M) fclean -C mlx
	@rm -rf so_long

re: fclean all
