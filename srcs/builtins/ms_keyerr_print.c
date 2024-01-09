/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_keyerr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:44:16 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/09 21:45:19 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

void	ms_keyerr_export_print(char *str)
{
	g_exit_status = 1;
	write(2, "minishell: ", 11);
	write(2, "export: `", 9);
	write(2, str, ms_strlen(str));
	write(2, "': not a valid identifier\n", 26);
}

void	ms_keyerr_unset_print(char *str)
{
	g_exit_status = 1;
	write(2, "minishell: ", 11);
	write(2, "unset: `", 8);
	write(2, str, ms_strlen(str));
	write(2, "': not a valid identifier\n", 26);
}
