/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_libs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:12:11 by doukim            #+#    #+#             */
/*   Updated: 2024/01/15 22:35:38 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

int	ms_isalpha(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	ms_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ms_strndup(const char *s1, int n)
{
	size_t	len;
	char	*ret;
	size_t	idx;

	if (!s1)
		return (NULL);
	len = ms_strlen(s1) + 1;
	if (len > n + 1)
		len = n + 1;
	ret = (char *)malloc(len);
	if (!ret)
		return (NULL);
	idx = 0;
	while (idx + 1 < len)
	{
		ret[idx] = s1[idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}

char	*ms_strjoin(char const *s1, char const *s2)
{
	const size_t	len = ms_strlen(s1) + ms_strlen(s2);
	char *const		ret = (char *)malloc(len + 1);
	size_t			idx;
	size_t			idx2;

	if (!ret)
		return (NULL);
	idx = 0;
	idx2 = 0;
	while (s1[idx])
	{
		ret[idx] = s1[idx];
		idx++;
	}
	while (s2[idx2])
	{
		ret[idx] = s2[idx2];
		idx++;
		idx2++;
	}
	ret[idx] = '\0';
	return (ret);
}

char	*ms_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)s + idx);
	return (NULL);
}
