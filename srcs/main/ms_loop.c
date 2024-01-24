/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:03:18 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 11:11:00 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

// void lc()
// {
// 	system("leaks --list minishell");
// }

void	ms_free_info(t_minishell *info)
{
	free(info->readline);
	free(info->converted);
	ms_tokenlstfree(&info->tokenlist);
	ms_cmdfree(&info->cmdlist);
	ms_double_malloc_free((char ***)&info->fds);
	ms_double_malloc_free((char ***)&info->pipes);
}

void	ms_loop(t_minishell *info)
{
	while (1)
	{
		info->error = 0;
		ms_set_input_mode(info);
		ms_set_signal(SHELL, SHELL);
		info->readline = readline(READLINE_MSG);
		if (!info->readline)
		{
			write(2, "\033[1A\033[11Cexit\n", 15);
			ms_reset_term_mode(info);
			exit(g_exit_status);
		}
		if (info->readline[0] != '\0')
			add_history(info->readline);
		if (!info->error && (errno || ms_lexer(info)))
			ms_lexerror(info, &info->error);
		if (!info->error && (errno || ms_parser(info)))
			ms_parerror(info, &info->error);
		ms_set_execute_mode(info);
		if (!info->error)
			ms_executor(info);
		ms_reset_term_mode(info);
		ms_free_info(info);
	}
}
