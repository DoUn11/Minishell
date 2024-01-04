/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:01 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/04 22:36:18 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_pwd(void)
{
	char	buffer[PATH_MAX];

	getcwd(buffer, PATH_MAX);
	write(1, buffer, ms_strlen(buffer));
	write(1, "\n", 1);
}
