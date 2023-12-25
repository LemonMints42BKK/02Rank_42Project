# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 20:41:40 by pnopjira          #+#    #+#              #
#    Updated: 2023/03/31 20:16:43 by pnopjira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

M 			:= make
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
NAME_SERV 	:= server
SERVER		:= server.c
NAME_SERV_B	:= server_bonus
SERVER_BONUS:= server_bonus.c
NAME_CLIE 	:= client
CLIENT		:= client.c
NAME_CLIE_B	:= client_bonus
CLIENT_BONUS:= client_bonus.c
LIBFT		:= libft/libft.a

all: sub-$(M) $(NAME_CLIE) $(NAME_SERV)

$(NAME_CLIE) : $(CLIENT)
	$(CC) $(CFLAGS) -g -o $(NAME_CLIE) $(CLIENT) $(LIBFT)

$(NAME_SERV) : $(SERVER)
	$(CC) $(CFLAGS) -g -o $(NAME_SERV) $(SERVER) $(LIBFT)

bonus: sub-$(M) $(NAME_CLIE_B) $(NAME_SERV_B)

$(NAME_CLIE_B) : $(CLIENT_BONUS)
	$(CC) $(CFLAGS) -g -o $(NAME_CLIE_B) $(CLIENT_BONUS) $(LIBFT)

$(NAME_SERV_B) : $(SERVER_BONUS)
	$(CC) $(CFLAGS) -g -o $(NAME_SERV_B) $(SERVER_BONUS) $(LIBFT)

sub-$(M):
	$(M) -C libft

clean:
	$(M) -C libft clean
	rm -f *.o
	echo "clean .o in miniTalk"
	
fclean:
	$(M) -C libft fclean
	rm -rf $(NAME_CLIE)
	rm -rf $(NAME_SERV)
	rm -rf $(NAME_CLIE_B)
	rm -rf $(NAME_SERV_B)
	rm -rf *.dSYM
	echo "Fclean: miniTalk"

re: fclean all

.PHONY: all server client clean fclean re libft





