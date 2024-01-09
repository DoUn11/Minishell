/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:22:31 by doukim            #+#    #+#             */
/*   Updated: 2024/01/09 14:14:30 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

static int	ms_get_type(char *str)
{
	if (str == NULL)
		return (T_NULL);
	else if (!ms_strncmp(str, "|", 2))
		return (T_PIPE);
	else if (!ms_strncmp(str, "<", 2) || !ms_strncmp(str, ">", 2))
		return (T_REDIRECT);
	else if (!ms_strncmp(str, "<<", 3) || !ms_strncmp(str, ">>", 3))
		return (T_REDIRECT);
	else
		return (T_WORD);
}

static t_token	*ms_get_token(char *str)
{
	t_token	*ret;

	ret = (t_token *)malloc(sizeof(t_token));

	ret->str = ms_strdup(str);
	//printf("[[%d]]\n", ms_get_type(str));
	ret->type = ms_get_type(str);
	return (ret);
}

t_list	*ms_tokenize(t_list *splited)
{
	t_list	*ret;
	t_list	*tmp;
	
	ret = NULL;
	tmp = splited;
	while (tmp)
	{
		ms_lstadd(&ret, ms_get_token(tmp->data));
		printf("[token] : {%s, %d}\n", ms_get_token(tmp->data)->str, ms_get_token(tmp->data)->type);
		tmp = tmp->next;
	}
	ms_lstadd(&ret, ms_get_token(NULL));
	printf("[token] : {%s, %d}\n", ms_get_token(NULL)->str, ms_get_token(NULL)->type);
	return (ret);
}