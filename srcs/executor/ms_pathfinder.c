/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:41:36 by doukim            #+#    #+#             */
/*   Updated: 2024/01/19 10:02:26 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

char	**ms_get_envpath(char **envp)
{
	while (*envp)
	{
		if (!ms_strncmp(*envp, "PATH=", 5))
			return (ms_pathsplit(*envp + 5, ':'));
		envp++;
	}
	return (NULL);
}

char	*ms_get_cmdpath(char *filename, char **envpath)
{
	char	*cmdpath;
	char	*cmdtmp;

	cmdpath = ms_strjoin_f(ms_strdup("/"), ms_strdup(filename));
	while (*envpath)
	{
		cmdtmp = ms_strjoin_f(ms_strdup(*envpath), ms_strdup(cmdpath));
		if (!access(cmdtmp, X_OK))
		{
			free(cmdpath);
			return (cmdtmp);
		}
		envpath++;
		free(cmdtmp);
	}
	free(cmdpath);
	if (!access(filename, X_OK))
		return (ms_strdup(filename));
	return (ms_strdup(filename));
}