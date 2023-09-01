/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:20 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/01 16:30:30 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_cub(int ac, char **av)
{
	int	len;

	len = ft_strlen(av[1]);
	if (!ft_strncmp(av[1][len - 4], ".cub", 4))
		return (1);
	return (0);
}

//checks if data has been filled or not
//or if line was end of file and acts accordingly
int	check_done(char *line, t_data *data)
{
	
}

int	check_params(char *line, t_data *data)
{
	int	i;

	i = 0;
	i = skip_spaces(line, i);
	if (line[i] == 'N' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		;
	else if (line[i] == 'S' && line[i + 1] == 'O' && ft_isspace(line[i + 2]))
		;
	else if (line[i] == 'W' && line[i + 1] == 'E' && ft_isspace(line[i + 2]))
		;
	else if (line[i] == 'E' && line[i + 1] == 'A' && ft_isspace(line[i + 2]))
		;
	else if (line[i] == 'F' && ft_isspace(line[i + 1]))
		;
	else if (line[i] == 'C' && ft_isspace(line[i + 1]))
		;
}

int	check_file_data(int ac, char **av, t_data *data)
{
	int		mapfd;
	char	*buffer;

	mapfd = open(av[1], O_RDONLY, 0644);
	while (1)
	{
		buffer = get_next_line(mapfd);
		if (!buffer)
			return (check_done(buffer, data));
		check_params(buffer, data);
		free(buffer);
	}
}

int	parser(int ac, char **av, t_data *data)
{
	if (!check_cub(ac, av))
		return (write(1, "Error\n> wrong file format\n", 26));
	if (!check_file_data(ac, av, data))
		return (write(1, "Error\n> invalid file data\n", 26));
}
