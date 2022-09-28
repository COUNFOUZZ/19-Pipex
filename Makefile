# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabda <aabda@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 20:58:10 by aabda             #+#    #+#              #
#    Updated: 2022/09/28 18:30:32 by aabda            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
DIR		= srcs/
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS = $(DIR)child.c $(DIR)ft_split.c \
	$(DIR)ft_strjoin.c $(DIR)ft_strlen.c \
	$(DIR)ft_strncmp.c $(DIR)ft_substr.c \
	$(DIR)main.c $(DIR)path.c \
	$(DIR)utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re norm