/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_libs3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:50:39 by doukim            #+#    #+#             */
/*   Updated: 2024/01/10 07:45:37 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

char	*ms_strjoin_f(char *s1, char *s2)
{
	char *ret;
	
	ret = ms_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

int	ms_iswhitespace(int c)
{
	if (9 <= c && c <= 13 || c == 32)
		return (1);
	return (0);
}

static void	ms_strrev(char *s)
{
	const size_t	len = ms_strlen(s);
	size_t			idx;
	char			tmp;

	idx = 0;
	while (idx < len / 2)
	{
		tmp = s[idx];
		s[idx] = s[len - idx - 1];
		s[len - idx - 1] = tmp;
		idx++;
	}
	return ;
}

char	*ms_itoa(int n)
{
	char		revnum[35];
	long long	tmp;
	int			isminus;
	size_t		idx;

	if (!n)
		return (ms_strdup("0"));
	isminus = 0;
	if (n < 0)
		isminus = 1;
	tmp = (1LL - 2 * (n < 0)) * n;
	idx = 0;
	while (tmp)
	{
		revnum[idx++] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (isminus)
		revnum[idx++] = '-';
	revnum[idx] = '\0';
	ms_strrev(revnum);
	return (ms_strdup(revnum));
}

char	*ms_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	size_t			idx;
	const size_t	slen = ms_strlen(s);

	if (start > slen)
		len = 0;
	else if (start + len > slen)
		len = slen - start;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ret[idx] = s[start + idx];
		idx++;
	}
	ret[idx] = '\0';
	return (ret);
}
