/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:21:34 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 11:00:35 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

int	ms_parser(t_minishell *info)
{
	if (ms_syntax(info))
		return (1);
	if (ms_cmdlist(info))
		return (1);
	return (0);
}
