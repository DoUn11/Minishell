/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:18:21 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 17:33:30 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_check_builtin(t_minishell *info, t_list *arg_list)
{
	char	*builtin_cmd;
	char	**cmdarg_list;

	cmdarg_list = ((t_cmd *)arg_list->data)->cmdargs;
	builtin_cmd = ((t_cmd *)arg_list->data)->cmdargs[0];
	g_exit_status = 0;
	if (!ms_strncmp(builtin_cmd, "echo", 5))
		ms_echo_builtin(cmdarg_list);
	else if (!ms_strncmp(builtin_cmd, "cd", 3))
		ms_cd_buitin(info, cmdarg_list);
	else if (!ms_strncmp(builtin_cmd, "pwd", 4))
		ms_pwd_builtin();
	else if (!ms_strncmp(builtin_cmd, "export", 7))
		ms_export_builtin(info, cmdarg_list);
	else if (!ms_strncmp(builtin_cmd, "unset", 6))
		ms_unset_builtin(info, cmdarg_list);
	else if (!ms_strncmp(builtin_cmd, "env", 4))
		ms_env_builtin(info, cmdarg_list);
	else if (!ms_strncmp(builtin_cmd, "exit", 5))
		ms_exit_builtin(info, cmdarg_list);
	else
		return (0);
	return (1);
}
