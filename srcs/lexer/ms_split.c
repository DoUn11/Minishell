/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:42:13 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 10:57:34 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

int	ms_split_wspace_redir(t_list **ret, char **str, int *idx, char **word)
{
	while ((*str)[*idx] && ms_iswhitespace((*str)[*idx]))
		(*idx)++;
	(*str) += (*idx);
	*idx = 0;
	(*word) = ms_strdup("");
	while ((*str)[*idx] && ((*str)[*idx] == '<' || (*str)[*idx] == '>'))
	{
		(*idx) += 1 + ((*str)[*idx + 1] == (*str)[*idx]);
		(*word) = ms_strjoin_f((*word), ms_strndup((*str), *idx));
		(*str) += (*idx);
		*idx = 0;
		if (!*word)
			return (1);
		ms_lstadd(ret, (*word));
		if (!(*str)[*idx])
			return (0);
		(*word) = ms_strdup("");
	}
	return (0);
}

int	ms_split_pipe(t_list **ret, char **str, int *idx, char **word)
{
	while ((*str)[(*idx)] == '|')
	{
		(*idx)++;
		*word = ms_strjoin_f(*word, ms_strndup(*str, *idx));
		(*str) += (*idx);
		*idx = 0;
		if (!*word)
			return (1);
		ms_lstadd(ret, *word);
		if (!(*str)[(*idx)])
			return (0);
		*word = ms_strdup("");
	}
	return (0);
}

int	ms_split_quote(char **s, int *idx, char **word, t_list **ret)
{
	char	quote;

	while ((*s)[(*idx)] && !ms_iswhitespace((*s)[(*idx)]))
	{
		if ((*s)[(*idx)] == '<' || (*s)[(*idx)] == '>' || (*s)[(*idx)] == '|')
			break ;
		if ((*s)[(*idx)] == '\'' || (*s)[(*idx)] == '\"')
		{
			quote = (*s)[(*idx)];
			(*word) = ms_strjoin_f((*word), ms_strndup((*s), (*idx)));
			(*s) += (*idx) + ((*word)[0] != '\0');
			(*idx) = ((*word)[0] == '\0');
			while ((*s)[(*idx)] != quote)
				(*idx)++;
			(*word) = ms_strjoin_f((*word), ms_strndup((*s), (*idx)));
			(*s) += (*idx) + 1;
			(*idx) = -1;
		}
		quote = 0;
		(*idx)++;
	}
	*word = ms_strjoin_f(*word, ms_strndup((*s), *idx));
	if (!*word)
		return (1);
	return (ms_lstadd(ret, *word), 0);
}

t_list	*ms_split(char *str)
{
	t_list	*ret;
	char	*word;
	int		idx;

	ret = NULL;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] && ms_split_wspace_redir(&ret, &str, &idx, &word))
			return (NULL);
		if (str[idx] && ms_split_pipe(&ret, &str, &idx, &word))
			return (NULL);
		if (str[idx] && !ms_iswhitespace(str[idx]) && \
			str[idx] != '<' && str[idx] != '>' && \
			ms_split_quote(&str, &idx, &word, &ret))
			return (NULL);
		if (word && !word[0])
			free(word);
	}
	return (ret);
}
