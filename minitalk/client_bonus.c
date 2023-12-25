/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:37:49 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/31 20:18:29 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i--);
		if (c & shift)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
}

void	send_message(int pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}

int	send(int pid, char *str)
{
	if (kill(pid, 0) == -1)
		return (1);
	else
	{
		send_message(pid, str);
		return (0);
	}
}

void	fb_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Completed!", 1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argv[1])
		pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		signal(SIGUSR1, fb_handler);
		if (pid == 0)
		{
			ft_putstr_fd("Invalid PID\n", 2);
			return (1);
		}
		else
		{
			if (send(pid, argv[2]))
			{
				ft_putstr_fd("Invalid PID\n", 2);
				return (1);
			}
		}
	}
	else
		return (1);
	return (0);
}
