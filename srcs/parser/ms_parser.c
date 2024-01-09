/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:21:34 by doukim            #+#    #+#             */
/*   Updated: 2024/01/09 14:40:58 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_parser.h"

int	ms_parser(t_minishell *info)
{
	int		valid;

	valid = ms_syntax(info);
	if (valid == 0)
		return (1);
	printf("\n\nsyntax test passed\n\n");
	valid = ms_cmdlist(info);
	if (valid == 0)
		return (1);
	
	t_list *tmp = info->cmdlist;
	while (tmp)
	{
		printf("---------------------\n");
		int i;
		for(i = 0; ((t_cmd *)tmp->data)->cmdargs[i]; i++)
			printf("cmdargs[%d] : %s\n", i, ((t_cmd *)tmp->data)->cmdargs[i]);
		printf("\n");
		t_redirectlist *tmp2;
		for(tmp2 = ((t_cmd *)tmp->data)->redirects; tmp2 != NULL; tmp2 = tmp2->next)
			printf("redirect[%d] : %s\n", tmp2->redirect->type, tmp2->redirect->str);
		printf("\n");
		tmp = tmp->next;
	}
	return (0);
}