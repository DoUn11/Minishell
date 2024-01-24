/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:59:43 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 09:40:01 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

void	ms_lstfree(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = list;
	while (tmp)
	{
		free(tmp->data);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	list = NULL;
	return ;
}

void	ms_cmdfree(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = list;
	while (tmp)
	{
		ms_double_malloc_free(&((t_cmd *)tmp->data)->cmdargs);
		ms_tokenlstfree((((t_cmd *)tmp->data)->redirects));
		free(tmp->data);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	list = NULL;
	return ;
}

void	ms_tokenlstfree(t_list *list)
{
	t_tokenlist	*tmp;
	t_tokenlist	*tmp2;

	tmp = (t_tokenlist *)list;
	while (tmp)
	{
		free(tmp->token->str);
		free(tmp->token);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	list = NULL;
	return ;
}
