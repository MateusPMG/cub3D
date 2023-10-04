/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:21:00 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/04 15:20:17 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_textures(t_data *data, char *line, int i, int index)
{
	if (data->texture[index])
		return (print_error("Path duped"));
	i = skip_spaces(line, i);
	i++;
	if (!line[i])
		return (print_error("Invalid path to texture"));
	if (ft_strncmp(&line[ft_strlen(line) - 4], ".xpm", 4))
		return (print_error("Path not in xpm format"));
	if (access(&line[i], R_OK) == -1)
	{
		print_error("Textures: Cant access path");
		free_data(data);
		exit (1);
	}
	data->texture[index] = ft_substr(line, i, ft_strlen(line) - i);
	return (0);
}

int	fill_colours(t_data *data, char *line, int i, int index)
{
	char	**tmp;
	int		j;
	int		m;

	tmp = ft_split(&line[i], ',');
	if (!tmp[0] || !tmp[1] || !tmp[2] || (tmp[3] && free_double(tmp)))
		return (print_error("Wrong colour format"));
	j = -1;
	while (tmp[++j])
	{
		if (ft_strlen(tmp[j]) > 3 || ft_atoi(tmp[j]) > 255)
			return (print_error("Invalid colour value"));
		m = -1;
		while (tmp[j][++m])
			if (!ft_isdigit(tmp[j][m]) && free_double(tmp))
				return (print_error("Invalid colour value"));
	}
	if (index == 0)
		data->c_floor = ((ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8)
				+ (ft_atoi(tmp[2])));
	else
		data->c_ceiling = ((ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8)
				+ (ft_atoi(tmp[2])));
	free_double(tmp);
	return (0);
}

//checks if data has been filled or not
int	check_done(t_data *data)
{
	if (data->c_ceiling != -1 && data->c_floor != -1 && data->texture[0]
		&& data->texture[1] && data->texture[2] && data->texture[3])
		return (1);
	return (0);
}

int	alloc_map_2(int v, char *buffer, int mapfd, t_data *data)
{
	v = 0;
	while (1)
	{
		if (!buffer)
			break ;
		if (!buffer[0])
			return (print_error("Invalid map: empty line"));
		v++;
		if (ft_strlen(buffer) > data->map_x)
			data->map_x = ft_strlen(buffer);
		free(buffer);
		buffer = get_next_line(mapfd);
	}
	if (!v)
		return (print_error("Invalid map: no map"));
	else
	{
		data->map_y = v;
		data->map = (char **)malloc(sizeof(char *) * (v + 1));
	}
	data->map[v] = 0;
	close(mapfd);
	return (0);
}

int	alloc_map(t_data *data, char **av)
{
	int		mapfd;
	char	*buffer;
	int		v;

	v = data->gnl_x;
	mapfd = open(av[1], O_RDONLY, 0644);
	buffer = 0;
	while (1)
	{
		buffer = get_next_line(mapfd);
		if (v-- <= 0 && *buffer == '\0' && buffer)
			break ;
		if (buffer != 0)
			free(buffer);
	}
	if (!buffer[0])
		buffer = skip_empty_lines(buffer, &mapfd);
	if (alloc_map_2(v, buffer, mapfd, data))
		return (1);
	//if (buffer)
		//free(buffer);
	return (0);
}
