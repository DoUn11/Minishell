/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:03 by doukim            #+#    #+#             */
/*   Updated: 2024/01/19 14:05:42 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static int	ms_syntax_valid(int prev, int cur)
{
	if (prev == T_PIPE)
		return (!(cur == T_PIPE || cur == T_NULL));
	if (cur == T_PIPE)
		return (!(prev == T_PIPE || prev == -1));
	if (prev == T_R || prev == T_L || prev == T_LL || prev == T_RR)
		return (!(cur != T_WORD));
}
static int	ms_syntax_invalid(t_minishell *info, int cur)
{
	if (cur == T_NULL)
		info->errnum = 7;
	if (cur == T_L)
		info->errnum = 2;
	if (cur == T_R)
		info->errnum = 3;
	if (cur == T_LL)
		info->errnum = 4;
	if (cur == T_RR)
		info->errnum = 5;
	if (cur == T_PIPE)
		info->errnum = 6;
	return (1);
}
int	ms_syntax(t_minishell *info)
{
	t_tokenlist		*tmp;
	int				prev;
	int				cur;

	cur = -1;
	tmp = info->tokenlist;
	while (tmp)
	{
		prev = cur;
		cur = tmp->token->type;
		if (!ms_syntax_valid(prev, cur))
			return (ms_syntax_invalid(info, cur));
		tmp = tmp->next;
	}
	return (0);
}