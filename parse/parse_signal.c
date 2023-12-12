/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:54:40 by mapierre          #+#    #+#             */
/*   Updated: 2023/12/12 17:55:49 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// ctrl d
void	is_inside_sig(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}
// ctrl d
void	here_sig(int sig)
{
	if (sig == SIGINT)
		exit(1);
}
//CTRL C
void	handle_sigint(int sig)
{
	(void)sig;
	write(1, "\nMinishell> ", 12);
}

void	ft_exit(char *line, t_env *backup)
{
	write(1, "exit\n", 6);
	free(line);
	ft_free_lst(backup);
	exit(0);
}

void	init_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
