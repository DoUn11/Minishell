/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:54:42 by doukim            #+#    #+#             */
/*   Updated: 2023/12/28 04:32:40 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

t_list	*ms_lstnewnode(void *data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}

void	ms_lstadd(t_list **lst, void *data)
{
	t_list *tmp;

	if (!*lst)
	{
		*lst = ms_lstnewnode(data);
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ms_lstnewnode(data);
}