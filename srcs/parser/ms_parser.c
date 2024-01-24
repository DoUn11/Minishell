/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:21:34 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 10:25:53 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

int	ms_parser(t_minishell *info)
{
	int		valid;

	if (ms_syntax(info))
		return (1);
	if (ms_cmdlist(info))
		return (1);
	return (0);
}
