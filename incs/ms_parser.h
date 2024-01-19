/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:45:00 by doukim            #+#    #+#             */
/*   Updated: 2024/01/19 13:55:40 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_PARSER_H
# define MS_PARSER_H

# include "ms_minishell.h"

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_L 3
# define T_R 4
# define T_LL 5
# define T_RR 6

int		ms_parser(t_minishell *info);
int		ms_cmdlist(t_minishell *info);
int		ms_syntax(t_minishell *info);

#endif