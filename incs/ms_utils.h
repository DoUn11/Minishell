/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doukim <doukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:45:08 by doukim            #+#    #+#             */
/*   Updated: 2024/01/24 07:31:42 by doukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_UTILS_H
# define MS_UTILS_H

# include "ms_minishell.h"

void	ms_getenv(t_minishell *info, char **envp);
void	ms_getenv_copy(t_minishell *info, char **envp);
size_t	ms_strlen(const char *s);
char	*ms_strdup(const char *s1);
char	*ms_strndup(const char *s1, int n);
size_t	ms_strlcpy(char *dst, const char *src, size_t dstsize);
int		ms_strncmp(const char *s1, const char *s2, size_t n);
char	*ms_strjoin(char const *s1, char const *s2);
int		ms_isalpha(int c);
int		ms_isdigit(int c);
char	*ms_strchr(const char *s, int c);
char	*ms_strjoin_f(char *s1, char *s2);

t_list	*ms_lstnewnode(void *data);
void	ms_lstadd(t_list **lst, void *data);
int		ms_iswhitespace(int c);
char	*ms_itoa(int n);
char	*ms_substr(char const *s, unsigned int start, size_t len);

void	*ms_memset(void *b, int c, size_t len);
void	ms_lstfree(t_list *list);
void	ms_cmdfree(t_list *list);
void	ms_tokenlstfree(t_list *list);

#endif