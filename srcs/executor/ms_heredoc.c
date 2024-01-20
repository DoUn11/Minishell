/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:16:10 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/21 03:46:59 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

void	input_stream(t_minishell *info, t_redirect	*tmp, int temp_fd)
{
	char	*line;
	char	*add_nextline;

	ms_set_input_mode(info);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		add_nextline = ms_strjoin(tmp->str, "\n");
		if (!line)
		{
			free(add_nextline);
			break ;
		}
		if (!ms_strncmp(add_nextline, line, ms_strlen(line)))
		{
			free(add_nextline);
			free(line);
			break ;
		}
		write(temp_fd, line, ms_strlen(line));
		free(add_nextline);
		free(line);
	}
	ms_set_execute_mode(info);
}

int	ms_heredoc(t_minishell *info, t_redirect *tmp)
{
	int	temp_fd;


	temp_fd = ms_make_temp(info);
	if (temp_fd == -1)
	{
		perror("fail make temp");
		exit(1);
	}
	input_stream(info, tmp, temp_fd);
	return (temp_fd);
}
