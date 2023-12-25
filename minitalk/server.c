/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:56:40 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/31 19:48:53 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	rec(int bit, int pid)
{
	int			shift;
	static int	i = 7;
	static char	c = '\0';

	(void)pid;
	if (i == -1)
	{
		i = 7;
		c = '\0';
	}
	shift = 1 << i;
	if (bit != 0)
		c = (c | shift);
	i--;
	if (i == -1)
		ft_putchar_fd(c, 1);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		rec(0, info->si_pid);
	if (sig == SIGUSR2)
		rec(1, info->si_pid);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
