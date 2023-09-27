/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:28:57 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/27 17:05:24 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_map_2(t_data *data, int mapfd, char *buffer, int i)
{
	while (1)
	{
		buffer = get_next_line(mapfd);
		if (!buffer)
			return (print_error("Fatal error"));
		data->map[++i] = buffer;
		if (data->map[i][0] == '\0')
			break ;
	}
	return (0);
}

int	fill_map(char **av, t_data *data)
{
	int		mapfd;
	int		v;
	char	*buffer;
	int		i;

	v = data->gnl_x;
	mapfd = open(av[1], O_RDONLY, 0644);
	buffer = 0;
	while (1)
	{
		if (v-- <= 0 && *buffer != '\0')
			break ;
		if (buffer != 0)
			free(buffer);
		buffer = get_next_line(mapfd);
	}
	i = -1;
	data->map[++i] = buffer;
	if (fill_map_2(data, mapfd, buffer, i))
		return (1);
	return (0);
}

char	*skip_empty_lines(char *buffer, int *mapfd)
{
	while (1)
	{
		if (!buffer[0])
			buffer = get_next_line(*mapfd);
		if (buffer[0])
			break ;
	}
	return (buffer);
}
