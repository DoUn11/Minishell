/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:36 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 17:52:55 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_export_builtin(t_minishell *info, char **tk_list)
{
	if (tk_list[1] == 0)
		ms_export_no_arg(info);
	else
		ms_export_arg(info, tk_list);
}

void	ms_export_no_arg(t_minishell *info)
{
	int		i;
	int		export_size;
	char	*env_name;
	char	*env_value;

	i = 0;
	export_size = ms_get_listsize(info->export);
	ms_sort_export(info, export_size);
	while (i < export_size)
	{
		env_name = ms_get_envname(info->export[i]);
		env_value = ms_get_env_value(env_name, info->export);
		write(1, "declare -x ", 11);
		write(1, env_name, ms_strlen(env_name));
		if (ms_strchr(info->export[i], '=') != 0)
		{
			write(1, "=\"", 2);
			write(1, env_value, ms_strlen(env_value));
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		free(env_name);
		free(env_value);
		i++;
	}
}

void	ms_sort_export(t_minishell *info, int export_size)
{
	int	i;
	int	n;

	while (export_size--)
	{
		i = 0;
		while (info->export[i] && info->export[i + 1])
		{
			if (ms_strlen(info->export[i]) < ms_strlen(info->export[i + 1]))
				n = ms_strlen(info->export[i]);
			else
				n = ms_strlen(info->export[i + 1]);
			if (ms_strncmp(info->export[i], info->export[i + 1], n + 1) > 0)
				ms_swap_string(&info->export[i], &info->export[i + 1]);
			i++;
		}
	}
}

void	ms_swap_string(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
