/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:38 by doukim            #+#    #+#             */
/*   Updated: 2024/01/23 15:56:39 by doukim           ###   ########.fr       */
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
		return (1);
	}
	return (0);
}

void	ms_convert_1(t_minishell *info, t_convertinfo *c_info)
{
	c_info->start = c_info->idx + 1;
	c_info->ret = ms_strjoin_f(c_info->ret, ms_getvardata(info, c_info->var));
}

char	*ms_convert(t_minishell *info, char *str)
{
	t_quoteinfo		quotes;
	t_convertinfo	c_info;
	int				limiter;

	ms_convert_reset(&quotes, &c_info);
	limiter = 0;
	while (str && str[c_info.idx])
	{
		if (str[c_info.idx] == '#' && !(quotes.squote + quotes.dquote) \
		&& (!c_info.idx || ms_iswhitespace(str[c_info.idx - 1])))
			break ;
		ms_toggle_quote(&quotes, str[c_info.idx]);
		if (str[c_info.idx] == '$' && !quotes.squote && !limiter)
		{
			ms_dollar_convert(&c_info, &str);
			if (c_info.var == NULL)
			{
				ms_check_var_null(&c_info, &str);
				continue ;
			}
			ms_convert_1(info, &c_info);
		}
		if (limiter && !(quotes.squote + quotes.dquote) && ms_iswhitespace(str[c_info.idx]))
			limiter = 0;
		if (!(quotes.squote + quotes.dquote + limiter) && !ms_strncmp(str + c_info.idx, "<<", 2))
		{
			c_info.idx += 2;
			limiter = 1;
			while (ms_iswhitespace(str[c_info.idx]))
				c_info.idx++;
			c_info.idx--;
		}
		c_info.idx++;
	}
	if (!c_info.ret || ms_chk_quotes_closed(info, quotes, c_info.ret))
		return (NULL);
	return (ms_ret_join(&c_info, &str), c_info.ret);
}

/*
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
	while (str && str[idx])
	{
		ms_toggle_quote(&quotes, str[idx]);
		if (str[idx] == '$' && !quotes.squote)
		{
			ret = ms_strjoin_f(ret, ms_strndup(str + start, idx - start));
			idx++;
			var = ms_getvarname(str, &idx);
			if (var == NULL)
			{
				if (str[idx] != '\"' && str[idx] != '\'')
					ret = ms_strjoin_f(ret, ms_strdup("$"));
				start = idx;
				continue ;
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
*/