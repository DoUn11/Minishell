/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 00:19:42 by chanspar          #+#    #+#             */
/*   Updated: 2023/12/29 12:45:37 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_builtins.h"

int	ms_cd(char **tk_list)
{
	char	buffer[PATH_MAX];

	getcwd(buffer, PATH_MAX); //절대경로 버퍼에 복사
	ms_change_oldpwd(); // oldpwd에 저장
	if (tk_list[1] == 0)
		ms_cd_no_option();  //cd만 들어올 경우 홈으로 이동 
	else
		ms_cd_option(); //1.인자가 2개 들어온 경우 앞에꺼만 판단  2.-a 이런거 들어오면 그냥 안된다고 끝내기  3.-,~ 이런거 구현안해도됨
	
}
