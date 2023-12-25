/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unload_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <pnopjira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 03:07:27 by pnopjira          #+#    #+#             */
/*   Updated: 2023/04/21 00:46:57 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(char ***rows, int fd, int *i)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		print_error(ERR_MEMORY);
		return (0);
	}
	(*rows)[(*i)++] = line;
	return (1);
}

int	upload_map(t_map *plan, char *maps_path)
{
	int		fd2;
	int		i;
	char	**rows;

	i = 0;
	rows = (char **)malloc(((*plan).length + 1) * sizeof(char *));
	if (rows == NULL)
	{
		print_error(ERR_MEMORY);
		return (0);
	}
	fd2 = open(maps_path, O_RDONLY);
	while (i < (*plan).length)
	{
		if (!get_map(&rows, fd2, &i))
			return (0);
	}
	rows[i] = NULL;
	close(fd2);
	(*plan).map = &rows[0];
	return (1);
}
