/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:16:11 by doukim            #+#    #+#             */
/*   Updated: 2024/01/21 10:44:04 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_error.h"

void	ms_msherror(int errnum)
{
	errno = 0;
	if (errnum == 1)
		ms_perror("quote/dquote does not closed");
	if (errnum == 2)
		ms_perror("syntax error near unexpected token `<\'");
	if (errnum == 3)
		ms_perror("syntax error near unexpected token `>\'");
	if (errnum == 4)
		ms_perror("syntax error near unexpected token `<<\'");
	if (errnum == 5)
		ms_perror("syntax error near unexpected token `>>\'");
	if (errnum == 6)
		ms_perror("syntax error near unexpected token `|\'");
	if (errnum == 7)
		ms_perror("syntax error near unexpected token `newline\'");
}
void	ms_lexerror(t_minishell *info, int *error)
{
	*error = 1;
	g_exit_status = errno;
	if (errno == 0)
		ms_msherror(info->errnum);
	else
		ms_perror(strerror(errno));
}

void	ms_parerror(t_minishell *info, int *error)
{
	*error = 1;
	g_exit_status = errno;
	if (errno == 0)
		ms_msherror(info->errnum);
	else
		ms_perror(strerror(errno));
}

void	ms_file_error(char *filename, int errnum)
{
	if (errnum == 1)
		write(2, "No such file or directory\n", 27);
	if (errnum == 2)
		write(2, "command not found\n", 19);
	if (errnum == 3)
		write(2, "is a directory\n", 16);
}
void	ms_exeerror(t_minishell *info, char *filename, int errnum)
{
	write(2, "minishell: ", 12);
	write(2, filename, ms_strlen(filename));
	write(2, ": ", 3);
	if (errno == 0)
		ms_file_error(filename, errnum);
	else
		perror("");
}
