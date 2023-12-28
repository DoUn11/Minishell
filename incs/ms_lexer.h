/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:55 by doukim            #+#    #+#             */
/*   Updated: 2023/12/29 01:44:11 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_LEXER_H
# define MS_LEXER_H

# include "ms_minishell.h"

# define T_NULL 0
# define T_WORD 1
# define T_PIPE 2
# define T_REDIRECT 3

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

t_token	*ms_lexer(t_minishell *info);
t_list	*ms_split(char *str);
char	*ms_convert(t_minishell *info, char *str);
void	ms_toggle_quote(t_quoteinfo *quotes, char c);
char	*ms_getvarname(char *str, int *idx);
char	*ms_getvardata(t_minishell *info, char *var);
char	*ms_getparams(t_minishell *info, char c);
t_list	*ms_tokenize(t_list *splited);

#endif