# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doukim <doukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 01:31:34 by doukim            #+#    #+#              #
#    Updated: 2024/01/09 13:33:21 by doukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= cc
INCLUDE	:= -I./incs/
#CFLAGS	:= -Wall -Wextra -Werror

SRCDIR	:= ./srcs/
OBJDIR	:= ./objs/
INCDIR	:= ./incs/

SRCS	:= $(wildcard $(SRCDIR)lexer/*.c)\
	$(wildcard $(SRCDIR)main/*.c)\
	$(wildcard $(SRCDIR)utils/*.c)\
	$(wildcard $(SRCDIR)error/*.c)\
	$(wildcard $(SRCDIR)parser/*.c)
INCS	:= $(wildcard $(INCDIR)*.h)
OBJS	:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

$(OBJS) : $(OBJDIR)

$(OBJDIR) :
	@mkdir objs

$(OBJDIR)%.o : $(SRCDIR)main/%.c $(INCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#$(OBJDIR)%.o : $(SRCDIR)builtins/%.c $(INCS)
#	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)error/%.c $(INCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)excutor/%.c $(INCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)lexer/%.c $(INCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)utils/%.c $(INCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)parser/%.c $(INCS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
