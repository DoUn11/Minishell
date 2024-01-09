/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:34:41 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 17:40:01 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

void	ms_executor(t_minishell *info)
{
	t_list	*tmp;

	tmp = info->cmdlist;
	while (tmp)
	{
		if (ms_check_builtin(info, tmp) == 0)  //builtin 실행 안됐을때
		{
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}
