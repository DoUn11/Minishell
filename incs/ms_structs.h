/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:35:23 by doukim            #+#    #+#             */
/*   Updated: 2024/01/16 08:16:09 by doukim           ###   ########.fr       */
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

typedef struct s_minishell
{
	char				*arg;
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
}	t_minishell;

#endif