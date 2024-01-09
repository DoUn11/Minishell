/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:34:41 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/10 08:14:25 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

int	ms_get_pipe(t_minishell *info)
{
	int	idx;
	
	info->pipes = malloc(sizeof(int *) * info->cmdcnt - 1);
	if (!info->pipes)
		return (-1);
	idx = 0;
	while (idx < info->cmdcnt - 1)
	{
		info->pipes[idx] = malloc(sizeof(int) * 2);
		if (!info->pipes[idx])
			return (-1);
		if (pipe(info->pipes[idx]) == -1)
			return (-1);
		idx++;
	}
	return (0);
}

int	ms_get_fds(t_minishell *info)
{
	int	idx;
	
	info->fds = malloc(sizeof(int *) * info->cmdcnt);
	if (!info->fds)
		return (-1);
	idx = 0;
	while (idx < info->cmdcnt)
	{
		info->fds[idx] = malloc(sizeof(int) * 2);
		if (!info->fds[idx])
			return (-1);
		info->fds[idx][0] = 0;
		info->fds[idx][1] = 1;
		if (idx != 0)
			info->fds[idx][0] = info->pipes[idx - 1][1];
		if (idx != info->cmdcnt - 1)
			info->fds[idx][1] = info->pipes[idx][0];
		idx++;
	}
	return (0);
}

int	ms_executor(t_minishell *info)
{
	t_list	*tmp;
	int		idx;
	
	if (ms_get_pipe(info) == -1)
		return (1);
	if (ms_get_fds(info) == -1)
		return (1);
	tmp = info->cmdlist;
	
}
