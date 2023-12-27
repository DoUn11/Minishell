/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:38 by doukim            #+#    #+#             */
/*   Updated: 2023/12/28 03:34:50 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

void	ms_toggle_quote(t_quoteinfo *quotes, char c)
{
	quotes->squote ^= (c == '\'') & !quotes->dquote;
	quotes->dquote ^= (c == '\"') & !quotes->squote;
}

int	ms_chk_quotes_closed(t_minishell *info, t_quoteinfo q, char *ret)
{
	if (q.squote + q.dquote)
	{
		free(ret);
		info->errnum = 1;
		ms_strerror(info->errnum);
		return (1);
	}
	return (0);
}

char	*ms_convert(t_minishell *info, char *str)
{
	t_quoteinfo	quotes;
	int			idx;
	int			start;
	char		*var;
	char		*ret;

	quotes.squote = 0;
	quotes.dquote = 0;
	idx = 0;
	start = 0;
	ret = ms_strdup("");
	while (str[idx])
	{
		ms_toggle_quote(&quotes, str[idx]);
		if (str[idx] == '$' && !quotes.squote)
		{
			ret = ms_strjoin_f(ret, ms_strndup(str + start, idx - start));
			idx++;
			var = ms_getvarname(str, &idx);
			if (var == NULL)
			{
				ret = ms_strjoin_f(ret, ms_strdup("$"));
				start = idx;
				continue;
			}
			start = idx + 1;
			ret = ms_strjoin_f(ret, ms_getvardata(info, var));
		}
		idx++;
	}
	if (ms_chk_quotes_closed(info, quotes, ret))
		return (NULL);
	ret = ms_strjoin_f(ret, ms_strndup(str + start, idx - start));
	return (ret);
}