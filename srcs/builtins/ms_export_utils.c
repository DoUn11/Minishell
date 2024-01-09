/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:58:34 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/10 00:11:23 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_check_envexist(t_minishell *info, char *str)
{
	int		i;
	int		env_size;
	char	*env_name;

	i = 0;
	env_size = ms_get_listsize(info->envp);
	while (i < env_size)
	{
		env_name = ms_get_envname(info->envp[i]);
		if (ms_strncmp(env_name, str, ms_strlen(str) + 1) == 0)
		{
			free(env_name);
			return (i);
		}
		free(env_name);
		i++;
	}
	return (0);
}
