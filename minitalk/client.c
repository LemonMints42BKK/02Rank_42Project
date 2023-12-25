/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:56:36 by pnopjira          #+#    #+#             */
/*   Updated: 2023/03/27 22:28:04 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	int	pid;

	if (argv[1])
		pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
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
