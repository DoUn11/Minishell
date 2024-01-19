# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doukim <doukim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 01:31:34 by doukim            #+#    #+#              #
#    Updated: 2024/01/19 16:14:55 by doukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= cc -fsanitize=address
INCLUDE	:= -I./incs/
#CFLAGS	:= -Wall -Wextra -Werror

SRCDIR	:= ./srcs/
OBJDIR	:= ./objs/
INCDIR	:= ./incs/

SRCS	:= $(wildcard $(SRCDIR)lexer/*.c)\
	$(wildcard $(SRCDIR)main/*.c)\
	$(wildcard $(SRCDIR)utils/*.c)\
	$(wildcard $(SRCDIR)error/*.c)\
	$(wildcard $(SRCDIR)parser/*.c)\
	$(wildcard $(SRCDIR)builtins/*.c)\
	$(wildcard $(SRCDIR)executor/*.c)
INCS	:= $(wildcard $(INCDIR)*.h)
OBJS	:= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

$(OBJDIR) :
	@mkdir objs

$(OBJDIR)%.o : $(SRCDIR)main/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)builtins/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)error/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)executor/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)lexer/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)utils/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)parser/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
