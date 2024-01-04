/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 02:35:23 by doukim            #+#    #+#             */
/*   Updated: 2024/01/05 06:27:59 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_STRUCTS_H
# define MS_STRUCTS_H

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
	char		**export;
	char		*readline;
	char		*converted;
	t_list		*tokenlist;
	t_bintree	*ast;
	int			errnum;
}	t_minishell;

#endif