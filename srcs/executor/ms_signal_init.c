/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanspar <chanspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:20:17 by chanspar          #+#    #+#             */
/*   Updated: 2024/01/15 22:03:28 by chanspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_executor.h"

void	ms_save_input_mode(struct termios *original_term)
{
	if (tcgetattr(STDIN_FILENO, original_term) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
}

void	ms_reset_input_mode(struct termios *original_term)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, original_term) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
}

void	ms_set_input_mode(void)
{
	struct termios	new_term;

	if (tcgetattr(STDIN_FILENO, &new_term) == -1)
	{
		perror("tcgetattr");
		exit(1);
	}
	new_term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &new_term) == -1)
	{
		perror("tcsetattr");
		exit(1);
	}
	ms_set_signal(SHELL, SHELL);
	g_exit_status = 0;
}

void	ms_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ms_set_signal(int sig_int, int sig_quit)
{
	if (sig_int == IGNORE)
		signal(SIGINT, SIG_IGN);
	if (sig_int == DEFAULT)
		signal(SIGINT, SIG_DFL);
	if (sig_int == SHELL)
		signal(SIGINT, ms_signal_handler);
	if (sig_quit == IGNORE)
		signal(SIGQUIT, SIG_IGN);
	if (sig_quit == DEFAULT)
		signal(SIGQUIT, SIG_DFL);
	if (sig_quit == SHELL)
		signal(SIGQUIT, ms_signal_handler);
}

/*
자식에선 시그널 디폴트 값으로 
ms_set_signal(DEFAULT, DEFAULT);
pid = fork();
if (pid == 0)
{

}
else   부모에선 시그널 무시 
{
	closefd;
	ms_set_signal(IGNORE, IGNORE); 
}
*/

/* WIFSIGNALED 매크로를 사용하면 시그널에 의해 종료되었는지를 확인할 수 있고, WTERMSIG 매크로를 사용하면 어떤 시그널에 의한 건지를 알 수 있다. 
void	wait_child(void)
{
	int		status;
	int		signo;
	int		i;

	i = 0;
	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signo = WTERMSIG(status);
			if (signo == SIGINT && i++ == 0)
				write(2, "^C\n", 3);
			else if (signo == SIGQUIT && i++ == 0)
				write(2, "^\\Quit: 3\n", 10);
			g_exit_status = 128 + signo;
		}
		else
			g_exit_status = WEXITSTATUS(status);
	}
}
*/