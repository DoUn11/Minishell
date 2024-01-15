/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:21:06 by doukim            #+#    #+#             */
/*   Updated: 2024/01/15 23:34:41 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

char	*ms_getparams(t_minishell *info, char c)
{
	if (c == '0')
		return (ms_strdup(info->arg));
	if (c == '#')
		return (ms_strdup("0"));
	if (c == '?')
		return (ms_itoa(g_exit_status));
	return (ms_strdup(""));
}

char	*ms_getvarname(char *str, int *idx)
{
	int		len;

	if (str[*idx] == 0)
		return (NULL);
	str += *idx;
	len = 0;
	if (ms_isalpha(str[len]) || str[len] == '_')
	{
		while (ms_isalpha(str[len]) || ms_isdigit(str[len]) || str[len] == '_')
			len++;
	}
	else if (ms_strchr("1234567890!@#$*?-", str[len]))
		len++;
	if (len == 0)
		return (NULL);
	*idx += len - 1;
	return (ms_strjoin_f(ms_strndup(str, len), ms_strdup("=")));
}

char	*ms_getvardata(t_minishell *info, char *var)
{
	int		idx;

	if (ms_strlen(var) == 2 && ms_strchr("1234567890!@#$*?-", var[0]))
		return (ms_getparams(info, var[0]));
	else
	{
		idx = 0;
		while (info->envp[idx])
		{
			if (!ms_strncmp(info->envp[idx], var, ms_strlen(var)))
				return (ms_strdup(info->envp[idx] + ms_strlen(var)));
			idx++;
		}
		return (ms_strdup(""));
	}
}
