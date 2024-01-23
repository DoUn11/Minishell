/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:16:10 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/23 15:39:36 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

char	*ms_hdc_convert(t_minishell *info, char *line)
{
	int		idx;
	int		start;
	char	*ret;
	char	*var;

	ret = ms_strdup("");
	start = 0;
	idx = 0;
	while (line[idx])
	{
		if (line[idx] == '$')
		{
			ret = ms_strjoin_f(ret, ms_strndup(line + start, idx - start));
			idx++;
			var = ms_getvarname(line, &idx);
			if (var == NULL)
			{
				ret = ms_strjoin_f(ret, ms_strdup("$"));
				start = idx;
				continue ;
			}
			start = idx + 1;
			ret = ms_strjoin_f(ret, ms_getvardata(info, var));
		}
		idx++;
	}
	free(line);
	return (ret);
}
void	input_stream(t_minishell *info, t_redirect	*tmp, int temp_fd)
{
	char	*line;

	ms_set_input_mode(info);
	ms_set_signal(DEFAULT, DEFAULT);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			write(1, "\033[1A\033[2C", 8);
			break ;
		}
		if (!ms_strncmp(tmp->str, line, ms_strlen(tmp->str) + 1))
		{
			free(line);
			break ;
		}
		line = ms_hdc_convert(info, line);
		line = ms_strjoin_f(line, ms_strdup("\n"));
		write(temp_fd, line, ms_strlen(line));
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
	close(temp_fd);
	return (open(info->temp_file, O_RDONLY, 0644));
}
