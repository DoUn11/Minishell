/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:05 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/05 02:27:44 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

char	*ms_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ms_strlen(s);
	if (s == 0)
		return (0);
	if (start >= s_len)
		return (ms_strdup(""));
	if (start + len > s_len)
		tmp = (char *)malloc(sizeof(char) * (s_len - start + 1));
	else
		tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (0);
	while (i < len && *(s + start) != 0 && s[i] != 0)
	{
		*(tmp + i) = *(s + start);
		i++;
		start++;
	}
	*(tmp + i) = 0;
	return (tmp);
}

char	**ms_envp_copy(char **envp)
{
	char	**envp_copy;
	int		envp_size;
	int		i;

	i = 0;
	envp_size = ms_get_listsize(envp);
	envp_copy = malloc(sizeof(char *) * (envp_size + 1));
	if (!envp_copy)
		malloc_err();
	while (i < envp_size)
	{
		envp_copy[i] = ms_strdup(envp[i]);
		if (!envp_copy[i])
			malloc_err();
		i++;
	}
	envp_copy[i] = 0;
	return (envp_copy);
}

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

void	malloc_err(void)
{
	write(2, "malloc error!!\n", ms_strlen("malloc error!!\n"));
	exit(1);
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
