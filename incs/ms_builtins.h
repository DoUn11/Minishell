/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:49 by doukim            #+#    #+#             */
/*   Updated: 2024/01/05 03:38:04 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "ms_minishell.h"
# include "limits.h"

int		exit_status;

//echo
void	ms_echo_builtin(char **tk_list);
int	ms_check_echo_option(char *str);
void	ms_echo_no_option(char **tk_list);
void	ms_echo_option(char **tk_list, int idx);




//cd
void	ms_cd_buitin(t_minishell *info, char **tk_list);
void	ms_cd_no_arg(t_minishell *info, char buffer[PATH_MAX]);
void	ms_cd_arg(t_minishell *info, char buffer[PATH_MAX], char **tk_list);
void	ms_change_value(t_minishell *info, char buffer[PATH_MAX], char *name);

//pwd
void	ms_pwd(void);

//export




void	sort_envp(char **envp, int env_size);
void	swap_string(char **str1, char **str2);



//utils
int		ms_get_listsize(char **tk_list);
void	malloc_err(void);
char	*ms_get_envname(char *envv);
char	*ms_get_env_value(char *env_name, char **envp);
char	**ms_envp_copy(char **envp);










#endif
