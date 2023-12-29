/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:20:01 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 12:07:58 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_pwd(void)
{
	char	buffer[PATH_MAX];

	getcwd(buffer, PATH_MAX);
	write(1, buffer, ms_strlen(buffer));
	write(1, "\n", 1);
	return (1);
}
