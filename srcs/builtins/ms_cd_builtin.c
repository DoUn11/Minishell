/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:19:42 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/26 21:21:42 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_cannot_find(void)
{
	write(2, "minishell: ", 12);
	write(2, "cannot find current directorty. please relaunch minishell.\n", 60);
}

void	ms_cd_buitin(t_minishell *info, char **tk_list)
{
	char	buffer[PATH_MAX];

	g_exit_status = 0;
	if (getcwd(buffer, PATH_MAX) == NULL)
	{
		ms_cannot_find();
		return ;
	}
	if (tk_list[1] == 0)
		ms_cd_no_arg(info, buffer);
	else
		ms_cd_arg(info, buffer, tk_list);
}

void	ms_cd_no_arg(t_minishell *info, char buffer[PATH_MAX])
{
	char	*path;

	path = ms_get_env_value("HOME", info->envp);
	if (path == 0)
	{
		write(2, "minishell: ", 11);
		write(2, "cd: ", 4);
		write(2, "HOME not set\n", 13);
		g_exit_status = 1;
	}
	else if (chdir(path) == -1)
		ms_print_path_err(path);
	else
	{
		ms_change_value(info, buffer, "OLDPWD=");
		if (getcwd(buffer, PATH_MAX) == NULL)
		{
			ms_cannot_find();
			return ;
		}
		ms_change_value(info, buffer, "PWD=");
	}
	free(path);
}

void	ms_cd_arg(t_minishell *info, char buffer[PATH_MAX], char **tk_list)
{
	char	*path;

	path = tk_list[1];
	if (chdir(path) == -1)
		ms_print_path_err(path);
	else
	{
		ms_change_value(info, buffer, "OLDPWD=");
		if (getcwd(buffer, PATH_MAX) == NULL)
		{
			ms_cannot_find();
			return ;
		}
		ms_change_value(info, buffer, "PWD=");
	}
}

void	ms_print_path_err(char *path)
{
	struct stat	filestat;

	write(2, "minishell: ", 12);
	write(2, "cd: ", 4);
	write(2, path, ms_strlen(path));
	lstat(path, &filestat);
	if (!S_ISDIR(filestat.st_mode))
		write(2, ": Not a directory\n", 19);
	else if (errno == EACCES)
		write(2, ": Permission denied\n", 21);
	else
		write(2, ": No such file or directory\n", 29);
	g_exit_status = 1;
}
