# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 16:03:55 by pnopjira          #+#    #+#              #
#    Updated: 2023/03/16 12:00:44 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET_EXEC := push_swap

SRCS := push_swap_utils_01.c\
		push_swap_utils_02.c\
		push_swap_utils_03.c\
		push_swap_utils_04.c\
		ft_check_error.c\
		stack_imprementation.c\
		list_of_instruct01.c\
		list_of_instruct02.c\
		small_stack_01.c\
		small_stack_02.c\
		cmp_is_sort.c\

NAME_PRINTF := libftprintf.a

SRC_PRINTF := ft_printf.c\
		ft_specifier.c
		
CC := gcc

CFLAGS := -g -Wall -Wextra -Werror

${TARGET_EXEC}: push_swap.c libftprintf.a
	$(CC) $(CFLAGS) $(SRCS) $^ -o $@

$(NAME_PRINTF):$(SRC_PRINTF)
	$(CC) $(CFLAGS) -c $(SRC_PRINTF) -I./
	@ar rcs $(NAME_PRINTF) *.o

all: $(TARGET_EXEC) $(NAME_PRINTF) 

clean:
	@rm -f *.o
	@echo "clean up all object!"
	
fclean: clean
	@rm -f $(NAME_PRINTF) $(TARGET_EXEC)
	@echo "fclean already"
	
re: fclean all

.PHONY: clean fclean all re
