/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:18:21 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/08 19:28:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

//대문자도 해야됨?  ECHO

void	ms_check_builtin(t_minishell *info, char **tk_list)
{
	char	*builtin_cmd;

	builtin_cmd = tk_list[0];
	g_exit_status = 0;
	if (!ms_strncmp(builtin_cmd, "echo", 5))
		ms_echo_builtin(tk_list);
	else if (!ms_strncmp(builtin_cmd, "cd", 3))
		ms_cd_buitin(info, tk_list);
	else if (!ms_strncmp(builtin_cmd, "pwd", 4))
		ms_pwd_builtin();
	else if (!ms_strncmp(builtin_cmd, "export", 7))
		ms_export_builtin(info, tk_list);
	else if (!ms_strncmp(builtin_cmd, "unset", 6))
		ms_unset_builtin(info, tk_list);
	else if (!ms_strncmp(builtin_cmd, "env", 4))
		ms_env_builtin(info, tk_list);
	else if (!ms_strncmp(builtin_cmd, "exit", 5))
		ms_exit_builtin(info, tk_list);
	else
		return (0);
}
