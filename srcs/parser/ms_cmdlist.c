/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmdlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:48:17 by doukim            #+#    #+#             */
/*   Updated: 2024/01/21 09:44:33 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static int	ms_get_cmd_argc(t_tokenlist *lst)
{
	int		cnt;

	cnt = 0;
	while (lst->token->type != T_PIPE && lst->token->type != T_NULL)
	{
		if (T_L <= lst->token->type && lst->token->type <= T_RR)
			lst = lst->next->next;
		else
		{
			cnt++;
			lst = lst->next;
		}
	}
	return (cnt);
}

static t_cmd	*ms_new_cmd_line(int argc)
{
	t_cmd	*ret;

	ret = malloc(sizeof(t_cmd));
	if (ret == NULL)
		return (NULL);
	ret->cmdargs = malloc(sizeof(char *) * (argc + 1));
	if (ret->cmdargs == NULL)
	{
		free(ret);
		return (NULL);
	}
	ret->redirects = NULL;
	return (ret);
}

static t_redirect	*ms_get_redirect(t_tokenlist *lst)
{
	t_redirect	*ret;

	ret = malloc(sizeof(t_redirect));
	if (ret == NULL)
		return (NULL);
	ret->type = lst->token->type - 2;
	ret->str = ms_strdup(lst->next->token->str);
	return (ret);
}

int	ms_cmdlist(t_minishell *info)
{
	int				cmdargc;
	int				idx;
	t_tokenlist		*tmp;
	t_cmd			*cmdline;
	t_redirect		*redirect;
	
	info->cmdlist = NULL;
	info->cmdcnt = 0;
	tmp = (t_tokenlist *)info->tokenlist;
	while (tmp)
	{
		cmdargc = ms_get_cmd_argc(tmp);
		cmdline = ms_new_cmd_line(cmdargc);
		if (cmdline == NULL)
			return (1);
		idx = 0;
		while (tmp->token->type != T_PIPE && tmp->token->type != T_NULL)
		{
			if (T_L <= tmp->token->type && tmp->token->type <= T_RR)
			{
				redirect = ms_get_redirect(tmp);
				if (redirect == NULL)
					return (1);
				ms_lstadd(&cmdline->redirects, redirect);
				tmp = tmp->next->next;
				continue ;
			}
			cmdline->cmdargs[idx++] = ms_strdup(tmp->token->str);
			tmp = tmp->next;
		}
		cmdline->cmdargs[idx] = NULL;
		tmp = tmp->next;
		ms_lstadd(&info->cmdlist, cmdline);
		info->cmdcnt++;
	}
	if (errno)
		return (1);
	return (0);
}