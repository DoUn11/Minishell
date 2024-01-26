/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:16:10 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/26 17:17:30 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

char	*ms_append_char(char *str, char c)
{
	char	*ret;
	int		str_len;
	int		i;

	str_len = ms_strlen(str);
	i = 0;
	ret = malloc(sizeof(char) * (str_len + 2));
	while (i < str_len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	i++;
	ret[i] = '\0';
	if (str)
		free(str);
	return (ret);
}

int	ms_hdc_dollar(t_hdc *hdc, char **line, t_minishell *info)
{
	hdc->ret = ms_strjoin_f(hdc->ret, \
		ms_strndup(*line + hdc->start, hdc->idx - hdc->start));
	hdc->idx++;
	hdc->var = ms_getvarname(*line, &(hdc->idx));
	if (hdc->var == NULL)
	{
		hdc->ret = ms_strjoin_f(hdc->ret, ms_strdup("$"));
		hdc->start = hdc->idx;
		return (1);
	}
	hdc->start = hdc->idx + 1;
	hdc->ret = ms_strjoin_f(hdc->ret, ms_getvardata(info, hdc->var));
	free(hdc->var);
	return (0);
}

char	*ms_hdc_convert(t_minishell *info, char *line)
{
	t_hdc	hdc;

	hdc.ret = ms_strdup("");
	hdc.start = 0;
	hdc.idx = 0;
	while (line[hdc.idx])
	{
		if (line[hdc.idx] == '$')
		{
			if (ms_hdc_dollar(&hdc, &line, info) == 1)
				continue ;
		}
		else
			hdc.ret = ms_append_char(hdc.ret, line[hdc.idx]);
		hdc.idx++;
	}
	free(line);
	return (hdc.ret);
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
