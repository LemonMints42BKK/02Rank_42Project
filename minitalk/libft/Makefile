# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:09:55 by pnopjira          #+#    #+#              #
#    Updated: 2023/03/25 21:43:10 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isdigit.c\
      ft_atoi.c\
      ft_putchar_fd.c\
      ft_putstr_fd.c\
      ft_putnbr_fd.c\

all: $(NAME)

$(NAME):$(SRC)
	gcc $(FLAGS) -c $(SRC) -I./
	ar rcs $(NAME) *.o

clean:
	rm -f *.o
	echo "clean .o in libft"

fclean: clean
	rm -f $(NAME)
	echo "Fclean: libft"

re: fclean all

.PHONY: clean fclean all re
