# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 01:31:34 by doukim            #+#    #+#              #
#    Updated: 2024/01/19 16:17:05 by chanspar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell
CC		:= cc -fsanitize=address
INCLUDE	:= -I./incs/
#CFLAGS	:= -Wall -Wextra -Werror

SRCDIR	:= ./srcs/
OBJDIR	:= ./objs/
INCDIR	:= ./incs/

SRCS	:= $(SRCDIR)builtins/ms_builtin_utils.c\
	$(SRCDIR)builtins/ms_echo_builtin.c\
	$(SRCDIR)builtins/ms_export_arg_builtin.c\
	$(SRCDIR)builtins/ms_pwd_builtin.c\
	$(SRCDIR)builtins/ms_cd_builtin.c\
	$(SRCDIR)builtins/ms_env_builtin.c\
	$(SRCDIR)builtins/ms_export_builtin.c\
	$(SRCDIR)builtins/ms_unset_builtin.c\
	$(SRCDIR)builtins/ms_cd_utils_builtin.c\
	$(SRCDIR)builtins/ms_exit_atol.c\
	$(SRCDIR)builtins/ms_export_utils.c\
	$(SRCDIR)builtins/ms_unset_delete_builtin.c\
	$(SRCDIR)builtins/ms_check_builtins.c\
	$(SRCDIR)builtins/ms_exit_builtin.c\
	$(SRCDIR)builtins/ms_keyerr_print.c\
	$(SRCDIR)lexer/ms_convert.c \
	$(SRCDIR)lexer/ms_convert_utils.c \
	$(SRCDIR)lexer/ms_getvar.c \
	$(SRCDIR)lexer/ms_lexer.c \
	$(SRCDIR)lexer/ms_split.c \
	$(SRCDIR)lexer/ms_tokenizer.c \
	$(SRCDIR)utils/ms_getenv.c \
	$(SRCDIR)utils/ms_libs.c \
	$(SRCDIR)utils/ms_libs2.c \
	$(SRCDIR)utils/ms_libs3.c \
	$(SRCDIR)utils/ms_libs4.c \
	$(SRCDIR)utils/ms_list.c \
	$(SRCDIR)main/ms_main.c \
	$(SRCDIR)main/ms_loop.c \
	$(SRCDIR)error/ms_error_utils.c \
	$(SRCDIR)error/ms_errors.c \
	$(SRCDIR)parser/ms_cmdlist.c \
	$(SRCDIR)parser/ms_parser.c \
	$(SRCDIR)parser/ms_syntax.c \
	$(SRCDIR)executor/ms_executor.c \
	$(SRCDIR)executor/ms_executor_utils.c \
	$(SRCDIR)executor/ms_pathfinder.c \
	$(SRCDIR)executor/ms_pathsplit.c \
	$(SRCDIR)executor/ms_signal_init.c

INCS	:= $(INCDIR)ms_builtins.h \
	$(INCDIR)ms_executor.h \
	$(INCDIR)ms_minishell.h \
	$(INCDIR)ms_splash_screen.h \
	$(INCDIR)ms_utils.h \
	$(INCDIR)ms_error.h \
	$(INCDIR)ms_lexer.h \
	$(INCDIR)ms_parser.h \
	$(INCDIR)ms_structs.h
OBJS    := $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(OBJDIR) :
	mkdir -p objs

$(OBJDIR)%.o : $(SRCDIR)main/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)builtins/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)error/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)executor/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)lexer/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)utils/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)%.o : $(SRCDIR)parser/%.c $(INCS) | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
