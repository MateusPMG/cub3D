/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:20 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/06 13:52:08 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_cub(char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strncmp(&av[1][len - 4], ".cub", 4))
		return (1);
	return (0);
}

int	check_params(char *l, t_data *data)
{
	int	i;
	int	len;

	len = ft_strlen(l);
	if (len < 4)
		return (1);
	i = 0;
	i = skip_spaces(l, i);
	if (l[i] == 'N' && l[i + 1] == 'O' && fill_text(data, l, i + 2, 0))
		return (1);
	else if (l[i] == 'S' && l[i + 1] == 'O' && fill_text(data, l, i + 2, 1))
		return (1);
	else if (l[i] == 'W' && l[i + 1] == 'E' && fill_text(data, l, i + 2, 2))
		return (1);
	else if (l[i] == 'E' && l[i + 1] == 'A' && fill_text(data, l, i + 2, 3))
		return (1);
	else if (l[i] == 'F' && ft_isspace(l[i + 1])
		&& fill_colours(data, l, i + 2, 0))
		return (1);
	else if (l[i] == 'C' && ft_isspace(l[i + 1])
		&& fill_colours(data, l, i + 2, 1))
		return (1);
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
			break ;
		if (buffer[0] && check_params(buffer, data))
		{
			free(buffer);
			close (mapfd);
			return (2);
		}
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
	if (alloc_map(data, av))
		return (1);
	if (fill_map(av, data))
		return (1);
	if (validate_map(data))
		return (1);
	return (0);
}

int	parser(char **av, t_data *data)
{
	int	i;

	i = 3;
	if (!check_cub(av))
		return (print_error("wrong file type"));
	i = check_file_data(av, data);
	//if (check_file_format(av, data))
		//return (1);
	if (i == 0)
		return (print_error("wrong parameters"));
	else if (i == 2)
		return (1);
	if (check_map(av, data))
		return (1);
	return (0);
}
