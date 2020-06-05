# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalonso- <nalonso-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 08:09:03 by nalonso-          #+#    #+#              #
#    Updated: 2020/03/05 09:27:36 by nalonso-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

INCLUDE = ft_printf.h

FLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) ft_printf.h
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

%.o :	%.c
				gcc $(FLAGS) -c $< -o $@ -I.

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re:

.phony: all clean fclean re