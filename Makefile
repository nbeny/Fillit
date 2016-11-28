#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 10:09:13 by nbeny             #+#    #+#              #
#    Updated: 2016/11/28 10:22:23 by nbeny            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fillit

INCLUDE		=	fillit.h

SRCS		=	init_struct.c/


OBJS		=	init_struct.o/


CFLAGS		=	-Wall -Wextra -Werror

CC			=	/usr/bin/gcc

RM			=	/bin/rm -f

ECHO		=	/bin/echo -e


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all