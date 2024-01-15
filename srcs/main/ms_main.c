/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:27:36 by doukim            #+#    #+#             */
/*   Updated: 2024/01/13 20:41:38 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell		ms_info;
	struct termios	original_term;

	ms_save_input_mode(&original_term);
	if (argc > 1)
	{
		printf("Minishell has 0 args");
		return (0);
	}
	ms_set_input_mode();
	ms_memset(&ms_info, 0, sizeof(t_minishell));
	printf("%s\n", WELCOME_MSG);
	ms_info.arg = ms_strdup(argv[0]);
	ms_getenv(&ms_info, envp);
	ms_getenv_copy(&ms_info, envp);
	ms_loop(&ms_info);
	ms_reset_input_mode(&original_term);
	exit(0);
}
