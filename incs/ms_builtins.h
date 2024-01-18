/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:49 by doukim            #+#    #+#             */
/*   Updated: 2024/01/18 14:28:22 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_BUILTINS_H
# define MS_BUILTINS_H

# include "ms_minishell.h"
# include "limits.h"

int		ms_check_builtin(t_minishell *info, char **cmdargs, int pid);

//echo
void	ms_echo_builtin(char **tk_list);
int		ms_check_echo_option(char *str);
void	ms_echo_no_option(char **tk_list);
void	ms_echo_option(char **tk_list, int idx);

//cd
void	ms_cd_buitin(t_minishell *info, char **tk_list);
void	ms_cd_no_arg(t_minishell *info, char buffer[PATH_MAX]);
void	ms_cd_arg(t_minishell *info, char buffer[PATH_MAX], char **tk_list);
void	ms_print_path_err(char *path);
void	ms_change_value1(t_minishell *info, char buffer[PATH_MAX], char *name);
void	ms_change_value2(t_minishell *info, char buffer[PATH_MAX], char *name);
void	ms_change_value(t_minishell *info, char buffer[PATH_MAX], char *name);

//pwd
void	ms_pwd_builtin(void);

//export
void	ms_export_builtin(t_minishell *info, char **tk_list);
void	ms_export_no_arg(t_minishell *info);
void	ms_sort_export(t_minishell *info, int export_size);
void	ms_swap_string(char **str1, char **str2);

void	ms_export_arg(t_minishell *info, char **tk_list);
void	ms_check_key(t_minishell *info, char *str);
void	ms_keyerr_export_print(char *str);
int		ms_check_exist(t_minishell *info, char *str);
int		ms_check_envexist(t_minishell *info, char *str);
void	ms_add_key_value(char ***envp, char *str);
void	ms_change_key_value(t_minishell *info, char *str, int pos, char *key);
void	ms_check_key_utils(t_minishell *info, char *str, int i);

//unset
void	ms_unset_builtin(t_minishell *info, char **tk_list);
void	ms_unset_arg(t_minishell *info, char **tk_list);
void	ms_check_unset_key(t_minishell *info, char *str);
void	ms_delete_envp(t_minishell *info, char *str);
void	ms_keyerr_unset_print(char *str);

int		ms_check_exist_key(char **envp, char *str);
void	ms_memory_reduction(char ***envp, char *str);
void	ms_reduction_utils(char ***envp, char *s, char ***re_envp, int (*i)[2]);

//env
void	ms_env_builtin(t_minishell *info, char **tk_list);

//exit
void	ms_exit_builtin(t_minishell *info, char **tk_list, int pid);
void	ms_no_numeric_print(char *str);
void	ms_many_arg_print(void);

void	ms_check_numeric(unsigned long long num, int sign, int *flag);
void	ms_space_sign_skip(char **str, int *sign);

//utils
int		ms_get_listsize(char **tk_list);
char	*ms_get_envname(char *envv);
char	*ms_get_env_value(char *env_name, char **envp);
void	ms_double_malloc_free(char ***tmp);

#endif
