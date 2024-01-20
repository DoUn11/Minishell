/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:14:28 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/20 18:14:39 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_utils.h"

char	*ft_free(char **str)
{
	if (*str != 0)
	{
		free(*str);
		*str = 0;
	}
	return (0);
}

char	*make_line(long long idx, char *tmp)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * (idx + 2));
	if (line == 0)
		return (0);
	line[idx + 1] = 0;
	while (idx >= 0)
	{
		line[idx] = tmp[idx];
		idx--;
	}
	return (line);
}

char	*make_line_rest(char **rest)
{
	long long	idx;
	char		*line;
	char		*tmp;

	idx = 0;
	while ((*rest)[idx] && (*rest)[idx] != '\n')
		idx++;
	if ((*rest)[idx] == 0)
	{
		line = ms_strdup(*rest);
		ft_free(rest);
		if (line == 0)
			return (0);
		return (line);
	}
	tmp = *rest;
	*rest = ms_strdup(tmp + idx + 1);
	if (rest == 0 || *rest == 0)
		return (ft_free(&tmp));
	line = make_line(idx, tmp);
	ft_free(&tmp);
	if (line == 0)
		ft_free(rest);
	return (line);
}

char	*read_file(char *buff, char **rest, int fd)
{
	ssize_t	rd_size;
	char	*tmp;

	while (!ms_strchr(*rest, '\n'))
	{
		rd_size = read(fd, buff, 42);
		if (rd_size == -1)
			return (ft_free(rest));
		else if (rd_size == 0)
			break ;
		buff[rd_size] = 0;
		tmp = *rest;
		*rest = ms_strjoin(tmp, buff);
		ft_free(&tmp);
		if (rest == 0 || *rest == 0)
			return (0);
	}
	return (make_line_rest(rest));
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*rest;
	char		*line;

	if (fd < 0 || 42 <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * (42 + 1));
	if (buff == 0)
		return (ft_free(&rest));
	if (rest == 0)
		rest = ms_strdup("");
	if (rest == 0)
		return (ft_free(&buff));
	line = read_file(buff, &rest, fd);
	ft_free(&buff);
	if (line == 0 || *line == 0)
		return (ft_free(&line));
	return (line);
}
