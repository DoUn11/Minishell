/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_convert_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:46:45 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/18 20:48:47 by chanspar         ###   ########.fr       */
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
	if (c_info->ret == 0)
		malloc_err();
}

void	ms_dollar_convert(t_convertinfo *c_info, char **str)
{
	c_info->ret = ms_strjoin_f(c_info->ret, \
		ms_strndup(*str + c_info->start, c_info->idx - c_info->start));
	if (c_info->ret == 0)
		malloc_err();
	(c_info->idx)++;
	c_info->var = ms_getvarname(*str, &(c_info->idx));
}

void	ms_check_var_null(t_convertinfo *c_info, char **str)
{
	char	*tmp;

	if ((*str)[c_info->idx] != '\"' && (*str)[c_info->idx] != '\'')
	{
		tmp = ms_strdup("$");
		if (tmp == 0)
			malloc_err();
		c_info->ret = ms_strjoin_f(c_info->ret, tmp);
		if (c_info->ret == 0)
			malloc_err();
	}
	c_info->start = c_info->idx;
}

void	ms_ret_join(t_convertinfo *c_info, char **str)
{
	c_info->ret = ms_strjoin_f(c_info->ret, \
		ms_strndup(*str + c_info->start, c_info->idx - c_info->start));
	if (c_info->ret == 0)
		malloc_err();
}
