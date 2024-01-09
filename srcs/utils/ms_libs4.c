/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_libs4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:43:49 by doukim            #+#    #+#             */
/*   Updated: 2024/01/10 07:45:44 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

void	*ms_memset(void *b, int c, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
		((char *)b)[idx++] = (unsigned char)c;
	return (b);
}
