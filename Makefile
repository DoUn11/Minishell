# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doukim <doukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 01:31:34 by doukim            #+#    #+#              #
#    Updated: 2023/12/26 22:33:03 by doukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= cc
INCLUDE	:= -I./incs/
#CFLAGS	:= -Wall -Wextra -Werror

SRCDIR	:= ./srcs/
OBJDIR	:= ./objs/
INCDIR	:= ./incs/

SRCS	:= $(wildcard $(SRCDIR)*/*.c)

OBJS	:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS) : $(OBJDIR)

$(OBJDIR) :
	@mkdir objs

$(OBJDIR)%.o : ./srcs/main/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
