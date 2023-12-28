/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:16:11 by doukim            #+#    #+#             */
/*   Updated: 2023/12/29 01:36:44 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_error.h"

void	ms_perror()
{
	perror("minishell");
}

void	ms_strerror(int errnum)
{
	errno = 0;
	if (errnum == 0)
		perror("minishell: quote/dquote does not closed");
}

void	ms_lexererr(int errnum)
{
	
}