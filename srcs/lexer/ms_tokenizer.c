/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 08:22:31 by doukim            #+#    #+#             */
/*   Updated: 2024/01/10 01:44:25 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

int	ms_get_type(char *str)
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
	int		idx;

	ret = (t_token *)malloc(sizeof(t_token));
	ret->type = ms_get_type(str);
	if (str && (str[0] == '\"' || str[0] == '\''))
		str++;
	ret->str = ms_strdup(str);
	//printf("[[%d]]\n", ms_get_type(str));
	return (ret);
}

t_list	*ms_tokenize(t_list *splited)
{
	t_list	*ret;
	t_list	*tmp;
	t_token	*tokentmp;
	
	ret = NULL;
	tmp = splited;
	while (tmp)
	{
		tokentmp = ms_get_token(tmp->data);
		ms_lstadd(&ret, tokentmp);
		printf("[token] : {%s, %d}\n", tokentmp->str, tokentmp->type);
		tmp = tmp->next;
	}
	tokentmp = ms_get_token(NULL);
	ms_lstadd(&ret, tokentmp);
	printf("[token] : {%s, %d}\n", tokentmp->str, tokentmp->type);
	return (ret);
}