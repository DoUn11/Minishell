/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_libs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:24:32 by doukim            #+#    #+#             */
/*   Updated: 2024/01/21 03:38:25 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

size_t	ms_strlen(const char *s)
{
	size_t	idx;

	if (!s)
		return (0);
	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ms_strdup(const char *s1)
{
	size_t	len;
	size_t	idx;
	char	*ret;

	if (!s1)
		return (NULL);
	len = ms_strlen(s1) + 1;
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

size_t	ms_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	srcsize;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	idx = 0;
	while (src[idx] && idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize)
		dst[idx] = '\0';
	return (srcsize);
}

int	ms_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	if (!n)
		return (0);
	if (!s1 || !s2)
		return (1);
	idx = 0;
	while (s1[idx] && s1[idx] == s2[idx] && idx + 1 < n)
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
