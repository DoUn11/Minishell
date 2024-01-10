/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:53 by doukim            #+#    #+#             */
/*   Updated: 2024/01/10 09:38:34 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_EXECUTOR_H
# define MS_EXECUTOR_H

# include "ms_minishell.h"

void	ms_executor(t_minishell *info);

int		ms_make_temp(t_minishell *info);
int		ms_temp_utils(t_minishell *info);
#endif
