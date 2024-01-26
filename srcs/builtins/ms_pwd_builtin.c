/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:01 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/26 21:23:01 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_cannot_find1(void)
{
	write(2, "minishell: ", 12);
	write(2, "cannot find current directorty. please relaunch minishell.\n", 60);
}

void	ms_pwd_builtin(void)
{
	char	buffer[PATH_MAX];

	g_exit_status = 0;
	if (getcwd(buffer, PATH_MAX) == NULL)
	{
		ms_cannot_find1();
		exit(1);
	}
	write(1, buffer, ms_strlen(buffer));
	write(1, "\n", 1);
}
