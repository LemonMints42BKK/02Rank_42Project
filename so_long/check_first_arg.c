/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:31:59 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/08 09:13:06 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wrong_maps_path(char *maps_path)
{
	char	*begin;
	char	*end;
	int		len;

	begin = maps_path;
	len = ft_strlen(maps_path);
	end = maps_path + (len - 4);
	if (len == 0)
		return (1);
	if (ft_strncmp(begin, "maps/", 5) != 0)
		return (1);
	if (ft_strncmp(end, ".ber", 4) != 0)
		return (1);
	return (0);
}

int	openfile_error(char *maps_path)
{
	int	fd;

	fd = open(maps_path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	first_arg(int argc, char *maps_path)
{
	if (argc == 2)
	{
		if (wrong_maps_path(maps_path))
		{
			ft_putstr_fd("Error! Hint: maps/*.ber only\n", 2);
			return (ERR_ARG);
		}
		if (openfile_error(maps_path))
		{
			ft_putstr_fd("Error! fail to open .ber file\n", 2);
			return (ERR_ARG);
		}
		return (0);
	}
	else
		ft_putstr_fd("Error! Hint: ./so_long maps/*.ber\n", 2);
	return (ERR_ARG);
}
