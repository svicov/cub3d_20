# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbombur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/03 16:29:34 by dbombur           #+#    #+#              #
#    Updated: 2020/12/03 17:01:15 by dbombur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	  ft_memchr.c ft_memcmp.c\
      ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	  ft_strnstr.c ft_strncmp.c\
      ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	  ft_isprint.c ft_toupper.c ft_tolower.c\
      ft_calloc.c ft_strdup.c\
      ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	  ft_itoa.c ft_strmapi.c\
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY:	all clean fclean re

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I. -c $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all
