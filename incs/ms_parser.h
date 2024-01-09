/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:45:00 by doukim            #+#    #+#             */
/*   Updated: 2024/01/09 13:54:35 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSER_H
# define MS_PARSER_H

# include "ms_minishell.h"

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIRECT 3
# define T_L 1
# define T_R 2
# define T_LL 3
# define T_RR 4

typedef struct s_tokenlist
{
	t_token				*token;
	struct s_tokenlist	*next;
}	t_tokenlist;

typedef struct s_redirect
{
	int		type;
	char	*str;
}	t_redirect;

typedef struct s_redirectlist
{
	t_redirect				*redirect;
	struct s_redirectlist	*next;
}	t_redirectlist;

typedef struct s_cmd
{
	char	**cmdargs;
	t_list	*redirects;
}	t_cmd;

int		ms_parser(t_minishell *info);
int		ms_cmdlist(t_minishell *info);
int		ms_syntax(t_minishell *info);

#endif