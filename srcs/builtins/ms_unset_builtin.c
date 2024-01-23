/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:21:01 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/23 17:09:01 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_unset_builtin(t_minishell *info, char **tk_list)
{
	g_exit_status = 0;
	if (tk_list[1] == 0)
		return ;
	ms_unset_arg(info, tk_list);
}

void	ms_unset_arg(t_minishell *info, char **tk_list)
{
	int	i;
	int	tk_size;

	i = 1;
	tk_size = ms_get_listsize(tk_list);
	while (i < tk_size)
	{
		ms_check_unset_key(info, tk_list[i]);
		i++;
	}
}

void	ms_check_unset_key(t_minishell *info, char *str)
{
	int	i;

	if (str[0] != '_' && ms_isalpha(str[0]) != 1)
	{
		ms_keyerr_unset_print(str);
		return ;
	}
	i = 1;
	while (str[i])
	{
		if (ms_isalpha(str[i]) != 1 && ms_isdigit(str[i]) != 1 && str[i] != '_')
		{
			ms_keyerr_unset_print(str);
			return ;
		}
		i++;
	}
	ms_delete_envp(info, str);
}

void	ms_delete_envp(t_minishell *info, char *str)
{
	if (ms_check_exist_key(info->export, str) == 1)
		ms_memory_reduction(&info->export, str);
	if (ms_check_exist_key(info->envp, str) == 1)
		ms_memory_reduction(&info->envp, str);
}
