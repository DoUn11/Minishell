/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:18:21 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/16 08:37:31 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_check_builtin(t_minishell *info, char **cmdargs)
{
	char	*builtin_cmd;

	printf("{builtin}\n");
	builtin_cmd = cmdargs[0];
	g_exit_status = 0;
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
		ms_exit_builtin(info, cmdargs);
	else
		return (0);
	return (1);
}
