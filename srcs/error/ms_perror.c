/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:16:11 by doukim            #+#    #+#             */
/*   Updated: 2024/01/06 18:19:41 by chanspar         ###   ########.fr       */
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

void	malloc_err(void)
{
	write(2, "malloc error!!\n", ms_strlen("malloc error!!\n"));
	exit(1);
}
