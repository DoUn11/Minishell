/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:21:39 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 16:31:46 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

unsigned char	ms_atol(char *str, int *flag);

void	ms_exit_builtin(t_minishell *info, char **tk_list)
{
	int	flag;
	int	arg_size;

	flag = 0;
	arg_size = ms_get_listsize(tk_list);
	if (tk_list[1] == 0)
	{
		write(2, "exit\n", 5);
		exit(g_exit_status);
	}
	g_exit_status = ms_atol(tk_list[1], &flag);
	if (flag == 1)
	{
		ms_no_numeric_print(tk_list[1]);
		exit(g_exit_status);
	}
	if (arg_size > 2 && flag == 0)
	{
		ms_many_arg_print();
		return ;
	}
	exit(g_exit_status);
}

void	ms_no_numeric_print(char *str)
{
	write(2, "minishell: ", 11);
	write(2, "exit: ", 6);
	write(2, str, ms_strlen(str));
	write(2, ": numeric argument required\n", 28);
}

void	ms_many_arg_print(void)
{
	g_exit_status = 1;
	write(2, "minishell: ", 11);
	write(2, "exit: ", 6);
	write(2, "too many arguments\n", 19);
}
