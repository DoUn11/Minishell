/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:53 by doukim            #+#    #+#             */
/*   Updated: 2024/01/10 09:12:08 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTOR_H
# define MS_EXECUTOR_H

# include "ms_minishell.h"

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

int		ms_executor(t_minishell *info);

#endif
