/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:19:42 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/04 22:15:22 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_cd_buitin(t_minishell *info, char **tk_list)
{
	char	buffer[PATH_MAX];

	getcwd(buffer, PATH_MAX);
	if (tk_list[1] == 0)
		ms_cd_no_arg(info, buffer);
	else
		ms_cd_arg(info, buffer, tk_list);
	//지금 경로의 디렉토리를 삭제하고 cd .
	//cd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory
}

void	ms_cd_no_arg(t_minishell *info, char buffer[PATH_MAX])
{
	char	*path;

	path = ms_get_env_value("HOME", info->envp);
	if (path == 0)
	{
		write(2, "minishell: ", 11);
		write(2, "cd: ", 4);
		wirte(2, "HOME not set\n", 13);
		exit_status = 1;
	}
	else if (chdir(path) == -1)
	{
		write(2, "minishell: ", 11);
		write(2, "cd: ", 4);
		write(2, path, ms_strlen(path));
		write(2, ": No such file or directory\n", 28);
		exit_status = 1;
	}
	else
	{
		ms_change_value(info, buffer, "OLDPWD=");
		getcwd(buffer, PATH_MAX);
		ms_change_value(info, buffer, "PWD=");
	}
	free(path);
}

void	ms_cd_arg(t_minishell *info, char buffer[PATH_MAX], char **tk_list)
{
	char	*path;

	path = tk_list[1];
	if (chdir(path) == -1)
	{
		write(2, "minishell: ", 11);
		write(2, "cd: ", 4);
		write(2, path, ms_strlen(path));
		write(2, ": No such file or directory\n", 28);
		exit_status = 1;
	}
	else
	{
		ms_change_value(info, buffer, "OLDPWD=");
		getcwd(buffer, PATH_MAX);
		ms_change_value(info, buffer, "PWD=");
	}
}

void	ms_change_value(t_minishell *info, char buffer[PATH_MAX], char *name)
{
	int		i;
	int		env_size;
	char	*tmp_envp;

	i = 0;
	env_size = ms_get_listsize(info->envp);
	while (i < env_size)
	{
		if (!ms_strncmp(info->envp[i], name, ms_strlen(name)))
		{
			tmp_envp = info->envp[i];
			info->envp[i] = ms_strjoin(name, buffer);
			if (info->envp[i] == 0)
				malloc_err();
			free(tmp_envp);
			break ;
		}	
		i++;
	}
}
