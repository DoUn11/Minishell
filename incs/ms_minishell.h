/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:27:46 by doukim            #+#    #+#             */
/*   Updated: 2023/12/28 19:24:34 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MINISHELL_H
# define MS_MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <term.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_bintree
{
	void				*data;
	struct s_bintree	*left;
	struct s_bintree	*right;
}	t_bintree;

typedef struct s_quoteinfo
{
	int		squote;
	int		dquote;
}	t_quoteinfo;

typedef struct s_minishell
{
	char		*arg;
	char		**envp;
	char		*readline;
	char		*converted;
	t_list		*tokenlist;
	t_bintree	*ast;
	int			errnum;
}	t_minishell;

# include "ms_lexer.h"
# include "ms_parser.h"
# include "ms_builtins.h"
# include "ms_executor.h"
# include "ms_utils.h"
# include "ms_splash_screen.h"
# include "ms_error.h"

void	ms_loop(t_minishell *info);

#endif