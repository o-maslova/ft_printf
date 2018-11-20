#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaslova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 18:15:17 by omaslova          #+#    #+#              #
#    Updated: 2018/11/20 15:29:08 by omaslova         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LIB = ./libft/libft.a

SRC = ./ft_printf.c \
	./integer.c \
	./uinteger.c \
	./string.c \
	./ft_itoa_base.c \
	./o_and_x.c \
	./parsing.c \
	./output.c \
	./cast.c \
	./unicode.c \
	./extra_fun.c

FLAGS = -Wall -Wextra -Werror

BINS = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	make -C libft

$(NAME): $(BINS) $(LIB)
	ar rc $(NAME) *.o

%.o: %.c
	gcc $(FLAGS) -o $@ -c $< -I libft

clean:
	make clean -C libft
	/bin/rm -r $(BINS)
	/bin/rm -f *~

fclean: clean
	make fclean -C libft
	/bin/rm -r $(NAME)

re: fclean all