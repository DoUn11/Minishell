/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:21:17 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/06 22:16:17 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_env_builtin(t_minishell *info, char **tk_list)
{
	int	i;
	int	env_size;

	if (tk_list[1] != 0)
		return ;
	i = 0;
	env_size = ms_get_listsize(info->envp);
	while (i < env_size)
	{
		write(1, info->envp[i], ms_strlen(info->envp[i]));
		write(1, "\n", 1);
		i++;
	}
}
