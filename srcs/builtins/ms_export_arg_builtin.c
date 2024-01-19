/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_arg_builtin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:57:07 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/16 10:10:05 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_check_key(t_minishell *info, char *str)
{
	int		i;

	if (str[0] != '_' && ms_isalpha(str[0]) != 1)
	{
		ms_keyerr_export_print(str);
		return ;
	}
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (ms_isalpha(str[i]) != 1 && ms_isdigit(str[i]) != 1 && str[i] != '_')
		{
			ms_keyerr_export_print(str);
			return ;
		}
		i++;
	}
	ms_check_key_utils(info, str, i);
}

int	ms_check_exist(t_minishell *info, char *str)
{
	int		i;
	int		export_size;
	char	*export_name;

	i = 0;
	export_size = ms_get_listsize(info->export);
	while (i < export_size)
	{
		export_name = ms_get_envname(info->export[i]);
		if (ms_strncmp(export_name, str, ms_strlen(str) + 1) == 0)
		{
			free(export_name);
			return (i);
		}
		free(export_name);
		i++;
	}
	return (0);
}

void	ms_add_key_value(char ***envp, char *str)
{
	int		i;
	int		envp_size;
	char	**re_envp;

	i = 0;
	envp_size = ms_get_listsize(*envp);
	re_envp = malloc(sizeof(char *) * (envp_size + 2));
	if (!re_envp)
		malloc_err();
	while (i < envp_size)
	{
		re_envp[i] = ms_strdup((*envp)[i]);
		if (!re_envp[i])
			malloc_err();
		i++;
	}
	re_envp[i] = ms_strdup(str);
	if (!re_envp[i])
		malloc_err();
	i++;
	re_envp[i] = 0;
	ms_double_malloc_free(envp);
	*envp = re_envp;
}

void	ms_change_key_value(t_minishell *info, char *str, int pos, char *key)
{
	char	*tmp_export;
	char	*tmp_env;
	int		env_pos;

	tmp_export = info->export[pos];
	info->export[pos] = ms_strdup(str);
	if (info->export[pos] == 0)
		malloc_err();
	free(tmp_export);
	env_pos = ms_check_envexist(info, key);
	if (env_pos == 0)
		ms_add_key_value(&(info->envp), str);
	else
	{
		tmp_env = info->envp[env_pos];
		info->envp[env_pos] = ms_strdup(str);
		if (info->envp[env_pos] == 0)
			malloc_err();
		free(tmp_env);
	}
}

void	ms_check_key_utils(t_minishell *info, char *str, int i)
{
	int		pos;
	char	*key;

	if (str[i] == 0)
	{
		if (ms_check_exist(info, str) == 0)
			ms_add_key_value(&(info->export), str);
	}
	else if (str[i] == '=')
	{
		key = ms_substr(str, 0, i);
		if (!key)
			malloc_err();
		pos = ms_check_exist(info, key);
		if (pos == 0)
		{
			ms_add_key_value(&(info->envp), str);
			ms_add_key_value(&(info->export), str);
		}
		else
			ms_change_key_value(info, str, pos, key);
		free(key);
	}
}
