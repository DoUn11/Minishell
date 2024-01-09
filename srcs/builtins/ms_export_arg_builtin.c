/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_arg_builtin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:57:07 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 15:11:38 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_export_arg(t_minishell *info, char **tk_list)
{
	int	i;
	int	tk_size;

	i = 1;
	tk_size = ms_get_listsize(tk_list);
	while (i < tk_size)
	{
		ms_check_key(info, tk_list[i]);
		i++;
	}
}

void	ms_check_key(t_minishell *info, char *str)
{
	int	i;

	if (str[0] != '_' && ms_isalpha(str[0]) != 1)
	{
		ms_keyerr_print(str);
		return ;
	}
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (ms_isalpha(str[i]) != 1 && ms_isdigit(str[i]) != 1 && str[i] != '_')
		{
			ms_keyerr_print(str);
			return ;
		}
		i++;
	}
	if (str[i] == 0)
		ms_check_exist(info, str);
	else if (str[i] == '=')
	{
		ms_add_key_value(&info->envp, str);
		ms_add_key_value(&info->export, str);
	}
}

void	ms_keyerr_print(char *str)
{
	g_exit_status = 1;
	write(2, "minishell: ", 11);
	write(2, "export: `", 9);
	write(2, str, ms_strlen(str));
	write(2, "': not a valid identifier\n", 26);
}

void	ms_check_exist(t_minishell *info, char *str)
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
			return ;
		}
		free(export_name);
		i++;
	}
	ms_add_key_value(&info->export, str);
}

void	ms_add_key_value(char ***envp, char *str)
{
	int		i;
	int		envp_size;
	char	**re_envp;
	char	***tmp;

	i = 0;
	envp_size = ms_get_listsize(*envp);
	re_envp = malloc(sizeof(char *) * (envp_size + 2));
	if (!re_envp)
		malloc_err();
	while (i < envp_size)
	{
		re_envp[i] = ms_strdup(*envp[i]);
		if (!re_envp[i])
			malloc_err();
		i++;
	}
	re_envp[i] = ms_strdup(str);
	if (!re_envp[i])
		malloc_err();
	i++;
	re_envp[i] = 0;
	tmp = envp;
	*envp = re_envp;
	ms_double_malloc_free(tmp);
}
