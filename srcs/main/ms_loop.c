/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:03:18 by doukim            #+#    #+#             */
/*   Updated: 2024/01/16 08:18:02 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

void	ms_loop(t_minishell *info)
{
	while (1)
	{
		ms_set_input_mode(info);
		info->readline = readline(READLINE_MSG);
		if (!info->readline)
		{
			write(2, "\033[1A\033[11Cexit\n", 15);
			break ;
		}
		if (info->readline[0] != '\0')
			add_history(info->readline);
		if (ms_lexer(info))
			continue ;
		if (ms_parser(info))
			continue ;
		ms_set_execute_mode(info);
		ms_executor(info);
		ms_reset_term_mode(info);
		free(info->readline);
	}
}
