/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmdlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:48:17 by doukim            #+#    #+#             */
/*   Updated: 2024/01/09 14:40:00 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static int	ms_get_cmd_argc(t_tokenlist *lst)
{
	int		cnt;

	cnt = 0;
	while (lst->token->type != T_PIPE && lst->token->type != T_NULL)
	{
		if (lst->token->type == T_REDIRECT)
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
	if (!ms_strncmp(lst->token->str, "<", 2))
		ret->type = 1;
	if (!ms_strncmp(lst->token->str, ">", 2))
		ret->type = 2;
	if (!ms_strncmp(lst->token->str, "<<", 3))
		ret->type = 3;
	if (!ms_strncmp(lst->token->str, ">>", 3))
		ret->type = 4;
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
	tmp = info->tokenlist;
	while (tmp)
	{
		ms_get_cmd_argc(tmp);
		cmdline = ms_new_cmd_line(cmdargc);
		if (cmdline == NULL)
			return (0);
		idx = 0;
		while (tmp->token->type != T_PIPE && tmp->token->type != T_NULL)
		{
			if (tmp->token->type == T_REDIRECT)
			{
				redirect = ms_get_redirect(tmp);
				if (redirect == NULL)
					return (0);
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
	}
	return (1);
}