/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:53 by doukim            #+#    #+#             */
/*   Updated: 2024/01/26 17:46:38 by chanspar         ###   ########.fr       */
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
char	*ms_get_cmdpath(char *filename, char **envpath);

void	ms_save_input_mode(struct termios *original_term);
void	ms_reset_term_mode(t_minishell *info);
void	ms_set_input_mode(t_minishell *info);
void	ms_set_execute_mode(t_minishell *info);
void	ms_signal_handler(int signo);
void	ms_set_signal(int sig_int, int sig_quit);

int		ms_heredoc(t_minishell *info, t_redirect *tmp);
void	ms_unlink_heredoc(t_minishell *info);

int		ms_get_pipe(t_minishell *info);
int		ms_get_fds(t_minishell *info);
void	ms_wait_child(void);
int		ms_get_redir_fd(t_minishell *info, t_redirect *redirect);
int		ms_get_redirects(t_minishell *info, t_list *redirects, int idx);

#endif