/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:18:21 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/24 10:55:34 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_check_builtin(t_minishell *info, char **cmdargs, int pid)
{
	char	*builtin_cmd;

	builtin_cmd = cmdargs[0];
	if (!ms_strncmp(builtin_cmd, "echo", 5))
		ms_echo_builtin(cmdargs);
	else if (!ms_strncmp(builtin_cmd, "cd", 3))
		ms_cd_buitin(info, cmdargs);
	else if (!ms_strncmp(builtin_cmd, "pwd", 4))
		ms_pwd_builtin();
	else if (!ms_strncmp(builtin_cmd, "export", 7))
		ms_export_builtin(info, cmdargs);
	else if (!ms_strncmp(builtin_cmd, "unset", 6))
		ms_unset_builtin(info, cmdargs);
	else if (!ms_strncmp(builtin_cmd, "env", 4))
		ms_env_builtin(info, cmdargs);
	else if (!ms_strncmp(builtin_cmd, "exit", 5))
		ms_exit_builtin(cmdargs, pid);
	else
		return (0);
	return (1);
}

int	ms_check_builtin_is(char **cmdargs)
{
	char	*builtin_cmd;

	builtin_cmd = cmdargs[0];
	if (!ms_strncmp(builtin_cmd, "cd", 3))
		return (1);
	else if (!ms_strncmp(builtin_cmd, "export", 7) && cmdargs[1] != NULL)
		return (1);
	else if (!ms_strncmp(builtin_cmd, "unset", 6))
		return (1);
	else if (!ms_strncmp(builtin_cmd, "exit", 5))
		return (1);
	return (0);
}
