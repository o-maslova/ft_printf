#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaslova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 18:15:17 by omaslova          #+#    #+#              #
#    Updated: 2018/07/31 18:17:52 by omaslova         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ./ft_printf.c ./integer.c ./uinteger.c ./string.c ./ft_itoa_base.c ./o_and_x.c ./parsing.c ./output.c ./cast.c ./unicode.c

FLAGS = -Wall -Wextra -Werror

LIBS = ./libft/libft.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) libft/*.c -I libft/libft.h
	gcc -c $(SRC)
	ar rc $(NAME) *.o
	
%.o%.c:
	gcc $(FLAGS) -o $< -c &< $(LIBS)

clean:
	rm -rf *.o libft/*.o
	rm -f *~

fclean: clean
	rm -rf $(NAME) libft/*.a

re: fclean all