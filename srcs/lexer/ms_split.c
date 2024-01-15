/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:42:13 by doukim            #+#    #+#             */
/*   Updated: 2024/01/16 08:38:41 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lexer.h"

// int	ms_split_redir(char **str, t_list **ret, int *idx)
// {
// 	char	*word;

// 	word = ms_strdup("");
// 	if (!word)
// 		malloc_err();
// 	while ((*str)[*idx] == '<' || (*str)[*idx] == '>')
// 	{
// 		*idx += 1 + ((*str)[*idx + 1] == (*str)[*idx]);
// 		word = ms_strjoin_f(word, ms_strndup(*str, *idx));
// 		if (!word)
// 			malloc_err();
// 		*str += *idx;
// 		*idx = 0;
// 		ms_lstadd(ret, word);
// 		if (!(*str)[*idx])
// 			return (1);
// 		word = ms_strdup("");
// 		if (!word)
// 			malloc_err();
// 	}
// 	free(word);
// 	return (0);
// }

// int	ms_split_pipe(char **str, t_list **ret, int *idx)
// {
// 	char	*word;

// 	word = ms_strdup("");
// 	if (!word)
// 		malloc_err();
// 	while ((*str)[*idx] == '|')
// 	{
// 		*idx++;
// 		word = ms_strjoin_f(word, ms_strndup(*str, *idx));
// 		if (!word)
// 			malloc_err();
// 		*str += *idx;
// 		*idx = 0;
// 		ms_lstadd(ret, word);
// 		if (!(*str)[*idx])
// 			return (1);
// 		word = ms_strdup("");
// 		if (!word)
// 			malloc_err();
// 	}
// 	free(word);
// 	return (0);
// }

// void	ms_handle_quote(char **str, char **word, int *idx, int quote)
// {
// 	while ((*str)[*idx] != '\0' && !ms_iswhitespace((*str)[*idx]))
// 	{
// 		if ((*str)[*idx] == '<' || (*str)[*idx] == '>' || (*str)[*idx] == '|')
// 			break ;
// 		if ((*str)[*idx] == '\'' || (*str)[*idx] == '\"')
// 		{
// 			quote = (*str)[*idx];
// 			*word = ms_strjoin_f(*word, ms_strndup(*str, *idx));
// 			if (!*word)
// 				malloc_err();
// 			*str += *idx + ((*word)[0] != '\0');
// 			*idx = ((*word)[0] == '\0');
// 			while ((*str)[*idx] != quote)
// 				*idx++;
// 			*word = ms_strjoin_f(*word, ms_strndup(*str, *idx));
// 			if (!*word)
// 				malloc_err();
// 			*str += *idx + 1;
// 			*idx = -1;
// 		}
// 		quote = 0;
// 		(*idx)++;
// 	}
// }

// void	ms_split_quote(char **str, t_list **ret, int *idx)
// {
// 	char	quote;
// 	char	*word;

// 	quote = 0;
// 	word = ms_strdup("");
// 	if (!word)
// 		malloc_err();
// 	ms_handle_quote(str, &word, idx, quote);
// 	word = ms_strjoin_f(word, ms_strndup(*str, *idx));
// 	if (!word)
// 		malloc_err();
// 	ms_lstadd(ret, word);
// }

// t_list	*ms_split(char *str)
// {
// 	t_list	*ret;
// 	int		idx;

// 	ret = NULL;
// 	idx = 0;
// 	while (str[idx])
// 	{
// 		while (str[idx] && ms_iswhitespace(str[idx]))
// 			idx++;
// 		str += idx;
// 		idx = 0;
// 		if (!str[idx])
// 			return (ret);
// 		if (ms_split_redir(&str, &ret, &idx) == 1)
// 			return (ret);
// 		if (ms_split_pipe(&str, &ret, &idx) == 1)
// 			return (ret);
// 		if (str[idx] && !ms_iswhitespace(str[idx]) \
// 			&& str[idx] != '<' && str[idx] != '>')
// 			ms_split_quote(&str, &ret, &idx);
// 	}
// 	return (ret);
// }


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
					str += idx + (word[0] != '\0');
					idx = (word[0] == '\0');
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
