/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_libs3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:50:39 by doukim            #+#    #+#             */
/*   Updated: 2023/12/28 03:15:40 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_minishell.h"

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