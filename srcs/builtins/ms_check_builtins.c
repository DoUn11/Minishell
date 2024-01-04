/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:18:21 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/04 22:14:50 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

//대문자도 해야됨?  ECHO

void	ms_check_builtin(char **tk_list)
{
	char	*builtin_cmd;

	builtin_cmd = tk_list[0];
	if (!ms_strncmp(builtin_cmd, "echo", 5))
		
	else if (!ms_strncmp(builtin_cmd, "cd", 3))
		;
	else if (!ms_strncmp(builtin_cmd, "pwd", 4))
		;
	else if (!ms_strncmp(builtin_cmd, "export", 7))
		;
	else if (!ms_strncmp(builtin_cmd, "unset", 6))
		;
	else if (!ms_strncmp(builtin_cmd, "env", 4))
		;
	else if (!ms_strncmp(builtin_cmd, "exit", 5))
		;
	else
		return (0);
}
