/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:05 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 12:32:53 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_get_listsize(char **tk_list)
{
	int	tk_size;

	tk_size = 0;
	if (!tk_list)
		return (0);
	while (tk_list[tk_size])
		tk_size++;
	return (tk_size);
}
