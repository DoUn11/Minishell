/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset_delete_builtin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:30:54 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 18:00:32 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_check_exist_key(char **envp, char *str)
{
	int		i;
	int		envp_size;
	char	*envp_name;

	i = 0;
	envp_size = ms_get_listsize(envp);
	while (i < envp_size)
	{
		envp_name = ms_get_envname(envp[i]);
		if (ms_strncmp(envp_name, str, ms_strlen(str) + 1) == 0)
		{
			free(envp_name);
			return (1);
		}
		free(envp_name);
		i++;
	}
	return (0);
}

void	ms_memory_reduction(char ***envp, char *str)
{
	int		idx[2];
	int		envp_size;
	char	*envp_name;
	char	**re_envp;

	idx[0] = 0;
	idx[1] = 0;
	envp_size = ms_get_listsize(*envp);
	re_envp = malloc(sizeof(char *) * (envp_size));
	if (!re_envp)
		malloc_err();
	while (idx[0] < envp_size)
	{
		ms_reduction_utils(envp, str, &re_envp, &idx);
	}
	re_envp[idx[1]] = 0;
	ms_replace_envp(envp, &re_envp);
}

void	ms_reduction_utils(char ***envp, char *s, char ***re_envp, int (*i)[2])
{
	char	*envp_name;

	envp_name = ms_get_envname(*envp[*i[0]]);
	if (ms_strncmp(envp_name, s, ms_strlen(s) + 1) == 0)
	{
		free(envp_name);
		(*i)[0]++;
	}
	else
	{
		free(envp_name);
		*re_envp[(*i)[1]] = ms_strdup(*envp[(*i)[0]]);
		if (!*re_envp[(*i)[1]])
			malloc_err();
		(*i)[0]++;
		(*i)[1]++;
	}
}

void	ms_replace_envp(char ***envp, char ***re_envp)
{
	char	***tmp;

	tmp = envp;
	*envp = *re_envp;
	ms_double_malloc_free(tmp);
}
