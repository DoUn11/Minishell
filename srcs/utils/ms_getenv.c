/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:07:08 by doukim            #+#    #+#             */
/*   Updated: 2023/12/29 02:39:02 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

void	ms_getenv(t_minishell *info, char **envp)
{
	int		size_envp;
	int		idx;

	size_envp = 0;
	while (envp[size_envp])
		size_envp++;
	info->envp = (char **)malloc(sizeof(char *) * (size_envp + 1));
	if (!info->envp)
		return ;
	idx = 0;
	while (idx < size_envp)
	{
		info->envp[idx] = ms_strdup(envp[idx]);
		idx++;
	}
	info->envp[idx] = NULL;
}