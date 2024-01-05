/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:42:13 by doukim            #+#    #+#             */
/*   Updated: 2024/01/05 10:00:21 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

t_list	*ms_split(char *str)
{
	t_list *ret;
	char	quote;
	char	*word;
	int idx;

	ret = NULL;
	idx = 0;
	while (str[idx])
	{
		while (str[idx] && ms_iswhitespace(str[idx]))
			idx++;
		str += idx;
		idx = 0;
		if (!str[idx])
			return (ret);
		word = ms_strdup("");
		while (str[idx] == '<' || str[idx] == '>')
		{
			idx += 1 + (str[idx + 1] == str[idx]);
			word = ms_strjoin_f(word, ms_strndup(str, idx));
			str += idx;
			idx = 0;
			ms_lstadd(&ret, word);
			if (!str[idx])
				return (ret);
			word = ms_strdup("");
		}
		while (str[idx] == '|')
		{
			idx++;
			word = ms_strjoin_f(word, ms_strndup(str, idx));
			str += idx;
			idx = 0;
			ms_lstadd(&ret, word);
			if (!str[idx])
				return (ret);
			word = ms_strdup("");
		}
		if (str[idx] && !ms_iswhitespace(str[idx]) && str[idx] != '<' && str[idx] != '>')
		{
			while (str[idx] && !ms_iswhitespace(str[idx]))
			{
				if (str[idx] == '<' || str[idx] == '>' || str[idx] == '|')
					break;
				if (str[idx] == '\'' || str[idx] == '\"')
				{
					quote = str[idx];
					word = ms_strjoin_f(word, ms_strndup(str, idx));
					str += idx + 1;
					idx = 0;
					while (str[idx] != quote)
						idx++;
					word = ms_strjoin_f(word, ms_strndup(str, idx));
					str += idx + 1;
					idx = -1;
				}
				quote = 0;
				idx++;
			}
			word = ms_strjoin_f(word, ms_strndup(str, idx));
			ms_lstadd(&ret, word);
		}
		else
			free(word);
	}
	return (ret);
}