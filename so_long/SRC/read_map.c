/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaoui <halaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:20:46 by halaoui           #+#    #+#             */
/*   Updated: 2023/11/17 15:20:46 by halaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **read_map(char *path)
{
    int     fd;
    char    *line;
    char    **map;
    char    *holder_map;

	holder_map = NULL;
    fd = open(path, O_RDONLY);
	if (fd < 0)
        ft_error("Error : File not found\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder_map = ft_strjoin(holder_map, line);
		free(line);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}
