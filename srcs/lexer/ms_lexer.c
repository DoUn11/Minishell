/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:36:20 by doukim            #+#    #+#             */
/*   Updated: 2023/12/28 04:36:51 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

t_token	*ms_lexer(t_minishell *info)
{
	t_list		*splited;
	t_list		*ret;
	
	info->converted = ms_convert(info, info->readline);
	if (info->converted == NULL)
		return (NULL);
	printf("[convert] : %s\n", info->converted);
	splited = ms_split(info->converted);
	
	printf("[splited]\n");
	t_list *tmp = splited;
	while (tmp)
	{
		printf("{%s}\n", tmp->data);
		tmp = tmp->next;
	}
	ret = ms_tokenize(splited);
	return (ret);
}