/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:03:18 by doukim            #+#    #+#             */
/*   Updated: 2023/12/29 01:43:19 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

void	ms_loop(t_minishell *info)
{
	while (1)
	{
		info->readline = readline(READLINE_MSG);
		info->tokenlist = ms_lexer(info);
		if (info->tokenlist == NULL)
			continue;
		//info->ast = ms_parser(info);
		//ms_executor(info->list);
	}
}