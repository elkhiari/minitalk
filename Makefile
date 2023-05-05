# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 16:15:32 by oelkhiar          #+#    #+#              #
#    Updated: 2023/05/05 16:15:33 by oelkhiar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : client server

client : client.c minitalk.h functions.c
	cc -Wall -Werror -Wextra client.c functions.c -o client
	
server : server.c minitalk.h functions.c
	cc -Wall -Werror -Wextra server.c functions.c -o server
	
clean :
	rm -rf client server

fclean :
	rm -rf client server

re : fclean all

.PHONY : clean fclean all