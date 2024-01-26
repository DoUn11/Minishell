/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:45:32 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/26 17:48:43 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

int	ms_get_pipe(t_minishell *info)
{
	int	idx;

	info->pipes = malloc(sizeof(int *) * info->cmdcnt);
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
	info->pipes[idx] = NULL;
	return (0);
}

int	ms_get_fds(t_minishell *info)
{
	int	idx;

	info->fds = malloc(sizeof(int *) * (info->cmdcnt + 1));
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
			info->fds[idx][0] = info->pipes[idx - 1][0];
		if (idx != info->cmdcnt - 1)
			info->fds[idx][1] = info->pipes[idx][1];
		idx++;
	}
	info->fds[idx] = NULL;
	return (0);
}

void	ms_wait_child(void)
{
	int		status;
	int		signo;
	int		i;

	i = 0;
	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT && i++ == 0)
				write(2, "\n", 2);
			else if (signo == SIGQUIT && i++ == 0)
				write(2, "Quit: 3\n", 9);
			g_exit_status = 128 + signo;
		}
		else
			g_exit_status = WEXITSTATUS(status);
	}
}

int	ms_get_redir_fd(t_minishell *info, t_redirect *redirect)
{
	int	ret;

	if (redirect->type == 1)
		ret = open(redirect->str, O_RDONLY, 0644);
	if (redirect->type == 2)
		ret = open(redirect->str, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (redirect->type == 3)
	{
		ret = ms_heredoc(info, redirect);
		if (ret != -1)
		{
			ms_lstadd((t_list **)&info->unlink_list, info->temp_file);
			if (!info->unlink_list)
			{
				perror("");
				exit(ENOMEM);
			}
		}
	}
	if (redirect->type == 4)
		ret = open(redirect->str, O_RDWR | O_CREAT | O_APPEND, 0644);
	return (ret);
}

int	ms_get_redirects(t_minishell *info, t_list *redirects, int idx)
{
	t_redirectlist	*redirtmp;

	redirtmp = (t_redirectlist *)redirects;
	while (redirtmp)
	{
		if (info->fds[idx][(redirtmp->redirect->type + 1) % 2] \
			!= (redirtmp->redirect->type + 1) % 2)
			close(info->fds[idx][(redirtmp->redirect->type + 1) % 2]);
		info->fds[idx][(redirtmp->redirect->type + 1) % 2] \
			= ms_get_redir_fd(info, redirtmp->redirect);
		if (info->fds[idx][(redirtmp->redirect->type + 1) % 2] == -1)
		{
			ms_exeerror(redirtmp->redirect->str, 1);
			g_exit_status = 1;
			return (-1);
		}
		redirtmp = redirtmp->next;
	}
	return (0);
}
