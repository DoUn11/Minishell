/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:05 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/06 22:20:08 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_get_listsize(char **tk_list)
{
	int	tk_size;

	tk_size = 0;
	if (!tk_list)
		return (0);
	while (tk_list[tk_size])
		tk_size++;
	return (tk_size);
}

char	*ms_get_envname(char *envv)
{
	int		idx;
	char	*env_name;

	idx = 0;
	while (envv[idx] && envv[idx] != '=')
		idx++;
	env_name = ms_substr(envv, 0, idx);
	if (!env_name)
		malloc_err();
	return (env_name);
}

char	*ms_get_env_value(char *env_name, char **envp)
{
	int		i;
	int		env_size;
	char	*env_value;
	char	*re_name;

	i = 0;
	env_size = ms_get_listsize(envp);
	re_name = ms_strjoin(env_name, "=");
	if (!re_name)
		malloc_err();
	while (i < env_size)
	{
		if (!ms_strncmp(envp[i], re_name, ms_strlen(re_name)))
		{
			env_value = ms_strdup(envp[i] + ms_strlen(re_name));
			if (!env_value)
				malloc_err();
			free(re_name);
			return (env_value);
		}
		i++;
	}
	free(re_name);
	return (0);
}

void	ms_double_malloc_free(char ***tmp)
{
	int	i;

	i = 0;
	while (*tmp[i] != 0)
	{
		free(*tmp[i]);
		i++;
	}
	if (*tmp != 0)
		free(*tmp);
}
