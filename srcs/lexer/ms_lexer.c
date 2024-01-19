/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:36:20 by doukim            #+#    #+#             */
/*   Updated: 2024/01/19 12:55:28 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

int	ms_lexer(t_minishell *info)
{
	t_list		*splited;
	t_list		*tmp;
	char		*strtmp;

	info->converted = ms_convert(info, info->readline);
	if (!info->converted)
		return (1);
	printf("[convert] : %s\n", info->converted);
	splited = ms_split(info->converted);
	if (!splited)
		return (1);
	printf("[splited]\n");
	tmp = splited;
	while (tmp)
	{
		strtmp = ms_strdup(tmp->data);
		printf("{%s}\n", strtmp);
		tmp = tmp->next;
	}
	info->tokenlist = ms_tokenize(splited);
	if (!info->tokenlist)
		return (1);
	return (0);
}
