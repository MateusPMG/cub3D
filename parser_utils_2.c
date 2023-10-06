/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:28:57 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/06 13:39:56 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_map_2(t_data *data, int mapfd, char *buffer, int i)
{
	while (1)
	{
		buffer = get_next_line(mapfd);
		if (!buffer)
			break ;
		data->map[++i] = buffer;
		if (data->map[i][0] == '\0')
			return (print_error("Map: empty line"));
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
		if (v-- <= 0 && *buffer == '\0' && buffer)
			break ;
		if (buffer != 0)
			free(buffer);
		buffer = get_next_line(mapfd);
	}
	if (!buffer[0])
		buffer = skip_empty_lines(buffer, &mapfd);
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
		if (!buffer)
			break ;
		if (!buffer[0])
		{
			free(buffer);
			buffer = get_next_line(*mapfd);
		}
		if (buffer && buffer[0])
			break ;
	}
	if (!buffer)
	{
		print_error("map missing");
		return (0);
	}
	return (buffer);
}

int	check_file_format(char **av, t_data *data)
{
	int		mapfd;
	int		v;
	char	*buffer;

	v = data->gnl_x;
	mapfd = open(av[1], O_RDONLY, 0644);
	buffer = 0;
	while (1)
	{
		if (v-- < -2 && buffer)
			break ;
		if (buffer != 0)
			free(buffer);
		buffer = get_next_line(mapfd);
	}
	if (buffer[0])
	{
		free(buffer);
		return (print_error("extra parameters"));
	}
	return (0);
}

int	return_free(char *buff)
{
	free(buff);
	return (1);
}
