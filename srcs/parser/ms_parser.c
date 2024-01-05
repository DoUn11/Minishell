/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:21:34 by doukim            #+#    #+#             */
/*   Updated: 2024/01/05 11:21:15 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

int	ms_parser(t_minishell *info)
{
	int		valid;

	valid = ms_syntax(info);
	if (valid == 0)
		return (1);
	valid = ms_cmdlist(info);
	if (valid == 0)
		return (1);
	return (0);
}