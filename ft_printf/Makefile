
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlonka <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 12:47:37 by nlonka            #+#    #+#              #
#    Updated: 2022/11/26 21:12:35 by nlonka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c utils.c printers.c

SRCO = ft_printf.o utils.o printers.o

all: $(NAME)

$(NAME):
	cc -Wall -Werror -Wextra -c $(SRC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(SRCO)

fclean:
	/bin/rm -rf $(NAME) $(SRCO)

re: fclean all

.PHONY: re fclean clean all
