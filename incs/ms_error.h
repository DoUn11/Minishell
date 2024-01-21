/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:51 by doukim            #+#    #+#             */
/*   Updated: 2024/01/21 09:35:00 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ERROR_H
# define MS_ERROR_H

# include "ms_minishell.h"

void	ms_perror(char *str);
void	ms_lexerror(t_minishell *info, int *error);
void	ms_parerror(t_minishell *info, int *error);
void	ms_exeerror(t_minishell *info, char *filename, int errnum);
void	ms_msherror(int errnum);
void	malloc_err(void);

#endif