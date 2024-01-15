/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:53 by doukim            #+#    #+#             */
/*   Updated: 2024/01/15 12:45:30 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTOR_H
# define MS_EXECUTOR_H

# include "ms_minishell.h"

int		ms_executor(t_minishell *info);

int		ms_make_temp(t_minishell *info);
int		ms_temp_utils(t_minishell *info);

char	**ms_pathsplit(char const *s, char c);
char	*ms_get_cmdpath(char *filename, char **envp);
#endif