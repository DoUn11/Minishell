/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:27:46 by doukim            #+#    #+#             */
/*   Updated: 2024/01/09 15:01:26 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MINISHELL_H
# define MS_MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <term.h>
# include "ms_structs.h"
# include "ms_lexer.h"
# include "ms_parser.h"
# include "ms_builtins.h"
# include "ms_executor.h"
# include "ms_splash_screen.h"
# include "ms_error.h"
# include "ms_utils.h"

unsigned char	g_exit_status;

void	ms_loop(t_minishell *info);

#endif