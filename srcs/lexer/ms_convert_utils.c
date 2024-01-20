/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:46:45 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/19 12:51:28 by doukim           ###   ########.fr       */
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

void	ms_check_var_null(t_convertinfo *c_info, char **str)
{
	if ((*str)[c_info->idx] != '\"' && (*str)[c_info->idx] != '\'')
		c_info->ret = ms_strjoin_f(c_info->ret, ms_strdup("$"));
	c_info->start = c_info->idx;
}

void	ms_ret_join(t_convertinfo *c_info, char **str)
{
	c_info->ret = ms_strjoin_f(c_info->ret, \
		ms_strndup(*str + c_info->start, c_info->idx - c_info->start));
}