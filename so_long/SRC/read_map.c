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

int	width_of_map(char	**map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static	int	validate_line(char *line)
{
	int	j;

	if (ft_strlen(line) == 1)
		return (0);
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != '1' && line[j] != '0' && line[j] != 'C' 
			&& line[j] != 'E' && line[j] != 'P')
			return (0);
		j++;
	}
	return (1);
}

char	**read_map(char *path)
{
	int		fd;
	char	*line;
	char	**map;
	char	*holder_map;

	holder_map = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nFile not found\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_line(line))
			return (free(line), free(holder_map), NULL);
		holder_map = ft_strjoin(holder_map, line);
		free(line);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}
