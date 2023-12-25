/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:36:26 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/21 00:14:56 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_width(t_map *plan, char *line)
{
	(*plan).width = (ft_strlen(line) - 1);
}

int	length_and_width(t_map *plan, int fd)
{
	int		length;
	char	*line;

	length = 0;
	line = NULL;
	while (line != NULL || length == 0)
	{
		line = get_next_line(fd);
		if (line == NULL && length == 0)
			return (0);
		if (line == NULL)
			break ;
		length++;
		if (length == 1)
			ft_width(plan, line);
		if (length != 0 && ((size_t)(*plan).width != (ft_strlen(line) - 1)))
		{
			free (line);
			return (0);
		}
		free(line);
	}
	(*plan).length = length;
	return (1);
}

int	invalid_map(int width, int length)
{
	if ((width < 6 && length < 3) || (length < 6 && width < 3))
		return (0);
	if ((width < 5 && length == 3) || (length < 5 && width == 3))
		return (0);
	return (1);
}

int	maps_size(t_map *plan, int fd1)
{
	ft_printf ("fd1:%d\n", fd1);
	if (!length_and_width(plan, fd1))
	{
		close(fd1);
		print_error(ERR_RECT);
		return (0);
	}
	if (!invalid_map((*plan).width, (*plan).length))
	{
		close(fd1);
		print_error(ERR_RECT);
		return (0);
	}
	return (1);
}
