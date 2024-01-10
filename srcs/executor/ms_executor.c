/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:34:41 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/10 10:03:16 by doukim           ###   ########.fr       */
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
int	ms_get_redir_fd(t_redirect *redirect)
{
	int	ret;
	
	if (redirect->type == 1)
		ret = open(redirect->str, O_RDONLY, 0644);
	if (redirect->type == 2)
		ret = open(redirect->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (redirect->type == 3)
		ret = ms_heredoc();
	if (redirect->type == 4)
		ret = open(redirect->str, O_RDWR | O_CREAT | O_APPEND, 0644);
	return (ret);
}

int	ms_executor(t_minishell *info)
{
	t_list			*tmp;
	t_redirectlist	*redirtmp;
	int				idx;
	int				idx2;
	int				pid;
	
	if (ms_get_pipe(info) == -1)
		return (1);
	if (ms_get_fds(info) == -1)
		return (1);
	tmp = info->cmdlist;
	idx2 = 0;
	while (tmp)
	{
		pid = fork();
		if (pid == 0) //child
		{
			redirtmp = ((t_cmd *)tmp->data)->redirects;
			idx = 0;
			while (redirtmp)
			{
				info->fds[idx][(redirtmp->redirect->type + 1) % 2] = ms_get_redir_fd(redirtmp->redirect);
				if (info->fds[idx][(redirtmp->redirect->type + 1) % 2] == -1)
					return (-1);
				idx++;
				redirtmp = redirtmp->next;
			}
			
			dup2(info->fds[idx2][0], STDIN_FILENO);
			dup2(info->fds[idx2][1], STDOUT_FILENO);
			cmdtmp = ms_get_cmdpath(((t_cmd *)tmp->data)->cmdargs[0]);
			execve(cmdtmp, ((t_cmd *)tmp->data)->cmdargs, info->envp);
		}
		else //parent
		{
			
		}
	}
}
