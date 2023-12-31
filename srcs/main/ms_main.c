/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:27:36 by doukim            #+#    #+#             */
/*   Updated: 2024/01/10 07:45:14 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

int main(int argc, char *argv[], char *envp[])
{
	t_minishell ms_info;
	
	if (argc > 1)
	{
		printf("Minishell has 0 args");
		return (0);
	}
	ms_memset(&ms_info, 0, sizeof(t_minishell));
	printf("%s\n", WELCOME_MSG);
	ms_info.arg = ms_strdup(argv[0]);
	ms_getenv(&ms_info, envp);
	ms_getenv_copy(&ms_info, envp);
	ms_loop(&ms_info);
	exit(0);
}
