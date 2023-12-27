/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:44:51 by doukim            #+#    #+#             */
/*   Updated: 2023/12/27 16:15:59 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ERROR_H
# define MS_ERROR_H

# include "ms_minishell.h"

void	ms_perror();
void	ms_strerror(int errnum);

#endif