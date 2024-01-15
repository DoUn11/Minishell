/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:03:18 by doukim            #+#    #+#             */
/*   Updated: 2024/01/13 15:48:40 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

void	ms_loop(t_minishell *info)
{
	while (1)
	{
		info->readline = readline(READLINE_MSG);
		if (ms_lexer(info))
			continue ;
		if (ms_parser(info))
			continue ;
		ms_executor(info);
		free(info->readline);
	}
}