/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:56:09 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 11:23:49 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

static size_t	ms_split_strptrlen(char const *s, char c)
{
	size_t	idx;
	size_t	ret;

	ret = 1;
	idx = 0;
	while (s[idx])
	{
		while (s[idx] && s[idx] == c)
			idx++;
		if (s[idx] && s[idx] != c)
		{
			while (s[idx] && s[idx] != c)
				idx++;
			ret++;
		}
	}
	return (ret);
}

static _Bool	ms_malloc_nullguard(char **ret, size_t ptridx, size_t len)
{
	ret[ptridx] = (char *)malloc(len + 1);
	if (!ret[ptridx])
	{
		while (ptridx > 0)
			free(ret[--ptridx]);
		free(ret);
		return (1);
	}
	return (0);
}

char	**ms_pathsplit(char const *s, char c)
{
	char		**ret;
	size_t		ptridx;
	size_t		len;

	ret = (char **)malloc(sizeof(char *) * ms_split_strptrlen(s, c));
	if (!ret)
		return (NULL);
	ptridx = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (ms_malloc_nullguard(ret, ptridx, len))
				return (NULL);
			ms_strlcpy(ret[ptridx++], s, len + 1);
			s += len;
		}
	}
	ret[ptridx] = NULL;
	return (ret);
}
