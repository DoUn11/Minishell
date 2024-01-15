/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:53 by doukim            #+#    #+#             */
/*   Updated: 2024/01/16 08:17:51 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTOR_H
# define MS_EXECUTOR_H

# include "ms_minishell.h"

int		ms_executor(t_minishell *info);

int		ms_make_temp(t_minishell *info);
int		ms_temp_utils(t_minishell *info);

char	**ms_pathsplit(char const *s, char c);

char	**ms_get_envpath(char **envp);
char	*ms_get_cmdpath(char *filename, char **envp);

void	ms_save_input_mode(struct termios *original_term);
void	ms_reset_term_mode(t_minishell *info);
void	ms_set_input_mode(t_minishell *info);
void	ms_set_execute_mode(t_minishell *info);
void	ms_signal_handler(int signo);
void	ms_set_signal(int sig_int, int sig_quit);


#endif