/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:55 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 00:21:57 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_LEXER_H
# define MS_LEXER_H

# include "ms_minishell.h"

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_L 3
# define T_R 4
# define T_LL 5
# define T_RR 6

int		ms_lexer(t_minishell *info);
t_list	*ms_split(char *str);
char	*ms_convert(t_minishell *info, char *str);
void	ms_toggle_quote(t_quoteinfo *quotes, char c);
char	*ms_getvarname(char *str, int *idx);
char	*ms_getvardata(t_minishell *info, char *var);
char	*ms_getparams(t_minishell *info, char c);
t_list	*ms_tokenize(t_list *splited);

void	ms_convert_reset(t_quoteinfo *quotes, t_convertinfo *c_info);
void	ms_dollar_convert(t_convertinfo *c_info, char **str);
void	ms_check_var_null(t_convertinfo *c_info, char **str);
void	ms_ret_join(t_convertinfo *c_info, char **str);
void	ms_convert_1(t_minishell *info, t_convertinfo *c_info);

#endif