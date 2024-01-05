/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:36:20 by doukim            #+#    #+#             */
/*   Updated: 2024/01/05 08:16:06 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

int	*ms_lexer(t_minishell *info)
{
	t_list		*splited;
	
	info->converted = ms_convert(info, info->readline);
	if (info->converted == NULL)
		return (1);
	printf("[convert] : %s\n", info->converted);
	splited = ms_split(info->converted);
	if (splited == NULL)
		return (1);
	printf("[splited]\n");
	t_list *tmp = splited;
	while (tmp)
	{
		printf("{%s}\n", tmp->data);
		tmp = tmp->next;
	}
	info->tokenlist = ms_tokenize(splited);
	if (info->tokenlist == NULL)
		return (1);
	return (0);
}