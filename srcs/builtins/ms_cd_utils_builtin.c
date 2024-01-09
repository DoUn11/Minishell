/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd_utils_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:51:32 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/06 19:53:15 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_change_value1(t_minishell *info, char buffer[PATH_MAX], char *name)
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

void	ms_change_value2(t_minishell *info, char buffer[PATH_MAX], char *name)
{
	int		i;
	int		export_size;
	char	*tmp_export;

	i = 0;
	export_size = ms_get_listsize(info->export);
	while (i < export_size)
	{
		if (!ms_strncmp(info->export[i], name, ms_strlen(name)))
		{
			tmp_export = info->export[i];
			info->export[i] = ms_strjoin(name, buffer);
			if (info->export[i] == 0)
				malloc_err();
			free(tmp_export);
			break ;
		}	
		i++;
	}
}

void	ms_change_value(t_minishell *info, char buffer[PATH_MAX], char *name)
{
	ms_change_value1(info, buffer, name);
	ms_change_value2(info, buffer, name);
}
