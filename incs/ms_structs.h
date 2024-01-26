/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:35:23 by doukim            #+#    #+#             */
/*   Updated: 2024/01/26 17:53:30 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCTS_H
# define MS_STRUCTS_H

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_cmd
{
	char	**cmdargs;
	t_list	*redirects;
}	t_cmd;

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

typedef struct s_quoteinfo
{
	int		squote;
	int		dquote;
}	t_quoteinfo;

typedef struct s_convertinfo
{
	int		idx;
	int		start;
	char	*var;
	char	*ret;
}	t_convertinfo;

typedef struct s_unlinklist
{
	char				*data;
	struct s_unlinklist	*next;
}	t_unlinklist;

typedef struct s_hdc
{
	int		idx;
	int		start;
	char	*ret;
	char	*var;
}	t_hdc;

typedef struct s_executor
{
	char			*cmdtmp;
	char			**envpath;
	int				idx;
	int				pid;
	int				flag;
}	t_exe;

typedef struct s_minishell
{
	char			*arg;
	char			**envp;
	char			**export;
	char			*readline;
	char			*converted;
	char			*temp_file;
	t_list			*tokenlist;
	t_list			*cmdlist;
	int				**fds;
	int				**pipes;
	int				cmdcnt;
	int				errnum;
	struct termios	old_term;
	struct termios	new_term;
	t_unlinklist	*unlink_list;
	int				error;
}	t_minishell;

#endif