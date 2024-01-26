/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:46:45 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/26 20:25:27 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

void	ms_convert_reset(t_quoteinfo *quotes, t_convertinfo *c_info)
{
	quotes->squote = 0;
	quotes->dquote = 0;
	c_info->idx = 0;
	c_info->start = 0;
	c_info->ret = ms_strdup("");
}

void	ms_dollar_convert(t_convertinfo *c_info, char **str)
{
	c_info->ret = ms_strjoin_f(c_info->ret, \
		ms_strndup(*str + c_info->start, c_info->idx - c_info->start));
	(c_info->idx)++;
	c_info->var = ms_getvarname(*str, &(c_info->idx));
}

void	ms_check_var_null(t_convertinfo *c_info, char **str, t_quoteinfo *q)
{
	if (((*str)[c_info->idx] != '\"' && (*str)[c_info->idx] != '\'') \
	|| q->dquote)
		c_info->ret = ms_strjoin_f(c_info->ret, ms_strdup("$"));
	c_info->start = c_info->idx;
}

void	ms_ret_join(t_convertinfo *c_info, char **str)
{
	c_info->ret = ms_strjoin_f(c_info->ret, \
		ms_strndup(*str + c_info->start, c_info->idx - c_info->start));
}

void	ms_convert_1(t_minishell *info, t_convertinfo *c_info)
{
	c_info->start = c_info->idx + 1;
	c_info->ret = ms_strjoin_f(c_info->ret, ms_getvardata(info, c_info->var));
	free(c_info->var);
}
