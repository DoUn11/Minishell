/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 08:23:03 by doukim            #+#    #+#             */
/*   Updated: 2024/01/09 14:18:53 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

static int	ms_syntax_valid(int prev, int cur)
{
	if (prev == T_PIPE)
		return (!(cur == T_PIPE || cur == T_NULL));
	if (cur == T_PIPE)
		return (!(prev == T_PIPE || prev == -1));
	if (prev == T_REDIRECT)
		return (!(cur != T_WORD));
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
			return (0);
		tmp = tmp->next;
	}
	return (1);
}