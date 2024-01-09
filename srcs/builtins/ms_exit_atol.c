/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit_atol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:54:47 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/10 01:30:40 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

unsigned char	ms_atol(char *str, int *flag)
{
	unsigned long long	num;
	int					sign;
	int					str_size;

	num = 0;
	sign = 1;
	str_size = 0;
	ms_space_sign_skip(&str, &sign);
	if (!*str)
		*flag = 1;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str_size++;
		str++;
	}
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str || str_size > 19)
		*flag = 1;
	ms_check_numeric(num, sign, flag);
	if (*flag == 1)
		return (255);
	return (num * sign);
}

void	ms_check_numeric(unsigned long long num, int sign, int *flag)
{
	if (num > (unsigned long long)LONG_MAX && sign == 1)
		*flag = 1;
	if (num > (unsigned long long)LONG_MAX + 1 && sign == -1)
		*flag = 1;
}

void	ms_space_sign_skip(char **str, int *sign)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}
