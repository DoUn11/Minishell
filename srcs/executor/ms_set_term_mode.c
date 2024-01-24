/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_term_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:21:17 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/24 11:22:42 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

void	ms_save_input_mode(struct termios *original_term)
{
	if (tcgetattr(STDIN_FILENO, original_term) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
}

void	ms_reset_term_mode(t_minishell *info)
{
	struct termios	original_term;

	original_term = info->old_term;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &original_term) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	ms_set_input_mode(t_minishell *info)
{
	info->new_term = info->old_term;
	info->new_term.c_lflag &= ~(IEXTEN | ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &info->new_term) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
	info->errnum = 0;
}

void	ms_set_execute_mode(t_minishell *info)
{
	info->new_term.c_lflag |= (IEXTEN | ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &info->new_term) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
}
