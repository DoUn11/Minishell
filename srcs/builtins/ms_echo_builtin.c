/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:14:03 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/04 22:15:23 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_echo_builtin(char **tk_list)
{
	int	option_exist;
	int	idx;

	if (tk_list[1] == 0)
		return (write(1, "\n", 1));
	option_exist = ms_check_echo_option(tk_list[1]);
	if (option_exist == 0)
		ms_echo_no_option(tk_list);
	else if (option_exist == 1)
	{
		idx = 2;
		if (tk_list[idx] == 0)
			return ;
		while (ms_check_echo_option(tk_list[idx]) == 1)
		{
			idx++;
			if (tk_list[idx] == 0)
				return ;
		}
		ms_echo_option(tk_list, idx);
	}
}

int	ms_check_echo_option(char *str)
{
	int	idx;

	if (str[0] == '\0' || str[0] != '-')
		return (0);
	if (str[1] != 'n')
		return (0);
	idx = 2;
	while (str[idx] == 'n')
		idx++;
	if (str[idx] != '\0')
		return (0);
	return (1);
}

void	ms_echo_no_option(char **tk_list)
{
	int	idx;

	idx = 1;
	while (tk_list[idx])
	{
		write(1, tk_list[idx], ms_strlen(tk_list[idx]));
		idx++;
	}
	write(1, "\n", 1);
}

void	ms_echo_option(char **tk_list, int idx)
{
	int	list_size;

	list_size = ms_get_listsize(tk_list);
	while (idx < list_size)
	{
		write(1, tk_list[idx], ms_strlen(tk_list[idx]));
		if (idx < list_size - 1)
			wirte(1, " ", 1);
		idx++;
	}
}
