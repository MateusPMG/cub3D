/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:20 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/12 16:00:35 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_cub(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strncmp(av[1][len - 4], ".cub", 4))
		return (1);
	return (0);
}

int	check_params(char *line, t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	if (len < 4)
		return (1);
	i = 0;
	i = skip_spaces(line, i);
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		fill_textures(line, data, i + 2, 0);
	else if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		fill_textures(line, data, i + 2, 1);
	else if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		fill_textures(line, data, i + 2, 2);
	else if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		fill_textures(line, data, i + 2, 3);
	else if (line[i] == 'F' && ft_isspace(line[i + 1]))
		fill_colours(data, line, i + 1, 0);
	else if (line[i] == 'C' && ft_isspace(line[i + 1]))
		fill_colours(data, line, i + 1, 1);
	return (0);
}

int	check_file_data(char **av, t_data *data)
{
	int		mapfd;
	char	*buffer;

	mapfd = open(av[1], O_RDONLY, 0644);
	while (1)
	{
		buffer = get_next_line(mapfd);
		if (!buffer)
			return (print_error("Not enough parameters"));
		check_params(buffer, data);
		free(buffer);
		data->gnl_x++;
		if (check_done(data))
			break ;
	}
	close (mapfd);
	if (!check_done(data))
		return (0);
	else
		return (1);
}

int	check_map(char **av, t_data *data)
{
	if (alloc_map(av, data))
		return (1);
	if (fill_map(av, data))
		return (1);
	if (validate_map(data))
		return (1);
}

int	parser(int ac, char **av, t_data *data)
{
	if (!check_cub(av))
		return (write(1, "Error\n> wrong file format\n", 26));
	if (!check_file_data(av, data))
		return (write(1, "Error\n> invalid file data\n", 26));
	if (!check_map(av, data))
		return (1);
}
