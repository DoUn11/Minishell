/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:36 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/05 02:50:00 by chanspar         ###   ########.fr       */
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
}

void	sort_envp(char **envp, int env_size)
{
	int	i;
	int	n;

	while (env_size--)
	{
		i = 0;
		while (envp[i] && envp[i + 1])
		{
			if (ms_strlen(envp[i]) < ms_strlen(envp[i + 1]))
				n = ms_strlen(envp[i]);
			else
				n = ms_strlen(envp[i + 1]);
			if (ms_strncmp(envp[i], envp[i + 1], n + 1) > 0)
				swap_string(&envp[i], &envp[i + 1]);
			i++;
		}
	}
}

void	swap_string(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
