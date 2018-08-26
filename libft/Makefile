#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaslova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 18:18:43 by omaslova          #+#    #+#              #
#    Updated: 2018/04/13 13:03:57 by omaslova         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

SRC = ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c ./ft_strdup.c ./ft_strcpy.c ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c ./ft_strnstr.c ./ft_strcmp.c ./ft_strncmp.c ./ft_atoi.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c ./ft_strclr.c ./ft_striter.c ./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_itoa.c ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putnbr.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lst_push_back.c ./ft_lst_print.c ./ft_lst_split.c ./ft_lst_swap.c ./ft_sqrt.c


NAME = libft.a

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) 

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -I./

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

