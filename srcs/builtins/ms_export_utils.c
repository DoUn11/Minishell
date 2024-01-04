/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:35:59 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/05 03:37:31 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	sort_envp(char **envp, int env_size)
{
	int	i;
	int	n;

	while (env_size--)
	{
		i = 0;
		while (envp[i] && envp[i + 1])
		{
			if (ms_strlen(envp[i]) < ms_strlen(envp[i + 1]))
				n = ms_strlen(envp[i]);
			else
				n = ms_strlen(envp[i + 1]);
			if (ms_strncmp(envp[i], envp[i + 1], n + 1) > 0)
				swap_string(&envp[i], &envp[i + 1]);
			i++;
		}
	}
}

void	swap_string(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
