/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:34:41 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/26 18:15:14 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

void	ms_close_unusing_fds(t_minishell *info, int idx)
{
	int	idx2;

	idx2 = 0;
	while (idx2 < info->cmdcnt - 1)
	{
		if (info->pipes[idx2][0] != info->fds[idx][0])
			close(info->pipes[idx2][0]);
		if (info->pipes[idx2][1] != info->fds[idx][1])
			close(info->pipes[idx2][1]);
		idx2++;
	}
	if (info->fds[idx][0] != 0)
		close(info->fds[idx][0]);
	if (info->fds[idx][1] != 1)
		close(info->fds[idx][1]);
}

void	ms_child(t_list *tmp, t_minishell *info, t_exe *ex)
{
	ms_set_signal(DEFAULT, DEFAULT);
	if (ms_check_builtin_is(((t_cmd *)tmp->data)->cmdargs) && info->cmdcnt == 1)
		exit(0);
	if (((t_cmd *)tmp->data)->cmdargs[0] == NULL)
		exit(0);
	dup2(info->fds[(ex->idx)][0], STDIN_FILENO);
	dup2(info->fds[(ex->idx)][1], STDOUT_FILENO);
	ms_close_unusing_fds(info, (ex->idx));
	if (ms_check_builtin(info, ((t_cmd *)tmp->data)->cmdargs, (ex->pid)))
		exit(g_exit_status);
	ex->envpath = ms_get_envpath(info->envp);
	ex->cmdtmp = ms_get_cmdpath(((t_cmd *)tmp->data)->cmdargs[0], ex->envpath);
	ms_double_malloc_free(&(ex->envpath));
	if (execve(ex->cmdtmp, ((t_cmd *)tmp->data)->cmdargs, info->envp) == -1)
	{
		ms_exeerror(NULL, 0);
		exit(errno);
	}
}

void	ms_parent(t_minishell *info, t_list *tmp, t_exe *ex)
{
	ms_set_signal(IGNORE, IGNORE);
	if ((ex->idx) > 0)
	{
		close(info->pipes[(ex->idx) - 1][0]);
		close(info->pipes[(ex->idx) - 1][1]);
	}
	if (ms_check_builtin_is(((t_cmd *)tmp->data)->cmdargs) && info->cmdcnt == 1)
	{
		ex->flag = 1;
		ms_check_builtin(info, ((t_cmd *)tmp->data)->cmdargs, (ex->pid));
	}
}

void	ms_close_unlink_wait(t_minishell *info, t_exe *ex)
{
	int	i;

	i = 0;
	while (i < info->cmdcnt)
	{
		if (info->fds[i][0] != 0)
			close(info->fds[i][0]);
		if (info->fds[i][1] != 1)
			close(info->fds[i][1]);
		i++;
	}
	ms_unlink_heredoc(info);
	if (!ex->flag)
		ms_wait_child();
	errno = g_exit_status;
}

int	ms_executor(t_minishell *info)
{
	t_list	*tmp;
	t_exe	ex;		

	ex.flag = 0;
	if (ms_get_pipe(info) == -1)
		return (1);
	if (ms_get_fds(info) == -1)
		return (1);
	tmp = info->cmdlist;
	(ex.idx) = 0;
	while (tmp)
	{
		if (ms_get_redirects(info, ((t_cmd *)tmp->data)->redirects, \
			(ex.idx)) == -1)
			break ;
		(ex.pid) = fork();
		if ((ex.pid) == 0)
			ms_child(tmp, info, &ex);
		else
			ms_parent(info, tmp, &ex);
		tmp = tmp->next;
		(ex.idx)++;
	}
	ms_close_unlink_wait(info, &ex);
	return (0);
}
