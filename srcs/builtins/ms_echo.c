/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:14:03 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 01:44:35 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"


int	check_echo_option(char *str)
{
	int	idx;

	if (str[0] == '\0' || str[0] != '-')
		return (0);
	if (str[1] != 'n')
		return (0);
	idx = 2;
	while (str[idx] == 'n')
		idx++;
	
}

void	echo_print(char **tk_list)
{
	int	flag;

	flag = check_echo_option();
	if (flag == 0)
		echo_no_option();
	else if (flag == 1)
		echo_option();    //echo -n or  -n -n -n -n -n -n or -nnnnnnnnnnnn 만약에 -n nnnnhi는nnnnnhi출력
}

