/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executor_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:17:07 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/24 06:43:46 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

int	ms_make_temp(t_minishell *info)
{
	int		fd;
	char	*tmp;

	info->temp_file = ms_strdup("/tmp/mytempfile_a");
	if (info->temp_file == 0)
		return (-1);
	while (access(info->temp_file, F_OK) == 0)
	{
		fd = ms_temp_utils(info);
		if (fd != -1)
			return (fd);
		tmp = info->temp_file;
		info->temp_file = ms_strjoin(tmp, "a");
		free(tmp);
		if (info->temp_file == 0)
			return (-1);
	}
	fd = open(info->temp_file, O_RDWR | O_CREAT, 0644);
	if (fd != -1)
		return (fd);
	return (-1);
}

int	ms_temp_utils(t_minishell *info)
{
	int	i;
	int	fd;

	i = 1;
	while (i < 26)
	{
		info->temp_file[ms_strlen(info->temp_file) - 1] = i + 'a';
		if (access(info->temp_file, F_OK) == -1)
		{
			fd = open(info->temp_file, O_RDWR | O_CREAT, 0644);
			if (fd != -1)
				return (fd);
		}
		i++;
	}
	return (-1);
}

void	ms_unlink_heredoc(t_minishell *info)
{
	t_unlinklist	*tmp;

	tmp = info->unlink_list;
	while (tmp)
	{
		unlink(tmp->data);
		tmp = tmp->next;
	}
}
