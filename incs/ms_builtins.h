/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:49 by doukim            #+#    #+#             */
/*   Updated: 2024/01/05 11:03:28 by chanspar         ###   ########.fr       */
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
void	ms_export_builtin(t_minishell *info, char **tk_list);
void	ms_export_no_arg(t_minishell *info);
void	sort_export(char **export, int export_size);
void	swap_string(char **str1, char **str2);

void	ms_export_arg(t_minishell *info, char **tk_list);
void	ms_check_key(t_minishell *info, char *str);
void	ms_keyerr_print(char *str);
void	ms_check_exist(t_minishell *info, char *str);
void	ms_add_key_value(char **envp, char *str);


void	sort_export(char **export, int export_size);
void	swap_string(char **str1, char **str2);
void	ms_keyerr_print(char *str);


//utils
int		ms_get_listsize(char **tk_list);
void	malloc_err(void);
char	*ms_get_envname(char *envv);
char	*ms_get_env_value(char *env_name, char **envp);
void	ms_double_malloc_free(char **tmp);
// char	**ms_envp_copy(char **envp);










#endif
