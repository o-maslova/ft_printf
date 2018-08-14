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

SRC = 

FLAGS = -Wall -Wextra -Werror

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft
	ar rc $(NAME) $(BINS)

%.o%.c:
	gcc $(FLAGS) -o $< -c &< $(LIBS)

clean:
	make clean -C libft
	rm -f $(BINS)
	rm -f *~

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all