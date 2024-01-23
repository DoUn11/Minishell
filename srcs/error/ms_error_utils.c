/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:15:30 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 00:38:23 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_error.h"

void	ms_perror(char *str)
{
	write(2, "minishell: ", 12);
	write(2, str, ms_strlen(str));
	write(2, "\n", 2);
}

void	malloc_err(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
