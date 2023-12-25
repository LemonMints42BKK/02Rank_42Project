# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 07:47:49 by pnopjira          #+#    #+#              #
#    Updated: 2022/12/23 11:17:50 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror 

NAME = libftprintf.a

SRC = ft_printf.c\
		ft_specifier.c
		
all: $(NAME)

$(NAME):$(SRC)
	$(CC) $(FLAGS) -c $(SRC) -I./
	@ar rcs $(NAME) *.o
	
clean:
	@rm -f *.o
	@echo "clean up all object!"
	
fclean: clean
	@rm -f $(NAME)
	@echo "fclean already"
	
re: fclean all

.PHONY: clean fclean all re
