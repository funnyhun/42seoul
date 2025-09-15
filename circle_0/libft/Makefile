# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:59:40 by minhulee          #+#    #+#              #
#    Updated: 2023/10/20 14:05:51 by minhulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

SRCS_M = ./srcs/ft_isalpha.c ./srcs/ft_isdigit.c ./srcs/ft_isalnum.c ./srcs/ft_isascii.c \
		 ./srcs/ft_isprint.c ./srcs/ft_strlen.c ./srcs/ft_memset.c ./srcs/ft_memcpy.c \
		 ./srcs/ft_bzero.c ./srcs/ft_memmove.c ./srcs/ft_strlcpy.c ./srcs/ft_strlcat.c \
		 ./srcs/ft_tolower.c ./srcs/ft_toupper.c ./srcs/ft_strchr.c ./srcs/ft_strrchr.c \
		 ./srcs/ft_strncmp.c ./srcs/ft_memchr.c ./srcs/ft_memcmp.c ./srcs/ft_strnstr.c \
		 ./srcs/ft_atoi.c ./srcs/ft_strdup.c ./srcs/ft_calloc.c ./srcs/ft_strdup.c \
		 ./srcs/ft_substr.c ./srcs/ft_strjoin.c ./srcs/ft_strtrim.c ./srcs/ft_split.c \
		 ./srcs/ft_itoa.c ./srcs/ft_strmapi.c ./srcs/ft_striteri.c ./srcs/ft_putchar_fd.c \
		 ./srcs/ft_putstr_fd.c ./srcs/ft_putendl_fd.c ./srcs/ft_putnbr_fd.c

SRCS_B = ./srcs/ft_lstnew_bonus.c \
		 ./srcs/ft_lstadd_front_bonus.c \
		 ./srcs/ft_lstlast_bonus.c \
		 ./srcs/ft_lstsize_bonus.c \
		 ./srcs/ft_lstadd_back_bonus.c \
		 ./srcs/ft_lstdelone_bonus.c \
		 ./srcs/ft_lstclear_bonus.c \
		 ./srcs/ft_lstiter_bonus.c \
		 ./srcs/ft_lstmap_bonus.c
		 
OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = libft.a

ifdef FLAG
	OBJS = $(OBJS_M) $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all :	$(NAME)

%.o :	%.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME)	:	$(OBJS)
	ar cr $@ $^

bonus :
	make all FLAG=1

clean :
	rm -f $(OBJS_M) $(OBJS_B)

fclean :
	make clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all bonus clean fclean re