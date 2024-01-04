/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:36 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/05 05:58:23 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_export_builtin(t_minishell *info, char **tk_list)
{
	if (tk_list[1] == 0)
		ms_export_no_arg(info->envp);
	else
		ms_export_arg();
}

void	ms_export_no_arg(char **envp)
{
	int		i;
	int		env_size;
	char	**envp_copy;

	i = 0;
	envp_copy = ms_envp_copy(envp);
	env_size = ms_get_listsize(envp_copy);
	sort_envp(envp_copy, env_size);
	while (i < env_size)
	{

		i++;
	}
}

void	ms_export_arg(char **tk_list)
{
	int	i;
	int	tk_size;

	i = 1;
	tk_size = ms_get_listsize(tk_list);
	while (i < tk_size)
	{
		ms_check_key(tk_list[i]);
		i++;
	}
}

void	ms_check_key(char *str)
{
	int	i;

	if (str[0] != '-' && ms_isalpha(str[0]) != 1)
	{
		exit_status = 1;
		ms_keyerr_print();
		return ;
	}
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (ms_isalpha(str[i]) != 1 && ms_isdigit(str[i]) != 1)
		{
			exit_status = 1;
			ms_keyerr_print();
			return ;
		}
		i++;
	}
	if (str[i] == 0)
	{
		//이미 존재시 그대로 놔두기 
		ms_export_add();
	}
	else if (str[i] == '=')
	{
		ms_env_add();
		ms_export_add();
	}

}

