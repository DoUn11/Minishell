/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:14:03 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 12:33:39 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

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

int	ms_echo_print(char **tk_list)
{
	int	flag;
	int	idx;

	if (tk_list[1] == 0)
		return (write(1, "\n", 1));
	flag = ms_check_echo_option(tk_list[1]);
	if (flag == 0)
		ms_echo_no_option(tk_list);
	else if (flag == 1)
	{
		idx = 2;
		while (ms_check_echo_option(tk_list[idx]) == 1)
			idx++;
		ms_echo_option(tk_list, idx);
	}
	return (1);
}
