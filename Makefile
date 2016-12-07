#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 17:47:31 by nbeny             #+#    #+#              #
#    Updated: 2016/12/06 22:43:35 by nbeny            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fillit

FLAGS	=	-g -Wall -Wextra -Werror

SRCS	=	check_valid.c\
			ft_stockt.c\
			ft_nbtminos.c\
			ft_tabt.c\
			ft_fillmap.c\
			ft_makemap.c\
			ft_printmap.c\
			ft_deletetetri.c\
			ft_resolver.c\
			main.c

OBJS	=	check_valid.o\
			ft_stockt.o\
			ft_nbtminos.o\
			ft_tabt.o\
			ft_fillmap.o\
			ft_makemap.o\
			ft_printmap.o\
			ft_deletetetri.o\
			ft_resolver.o\
			main.o

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
