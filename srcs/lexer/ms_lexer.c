/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:36:20 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 10:50:58 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

int	ms_lexer(t_minishell *info)
{
	t_list		*splited;

	info->converted = ms_convert(info, info->readline);
	if (!info->converted)
		return (1);
	splited = ms_split(info->converted);
	if (!splited)
		return (1);
	info->tokenlist = ms_tokenize(splited);
	if (!info->tokenlist)
		return (1);
	ms_lstfree(&splited);
	return (0);
}
