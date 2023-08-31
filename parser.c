/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:05:20 by mpatrao           #+#    #+#             */
/*   Updated: 2023/08/31 16:06:17 by mpatrao          ###   ########.fr       */
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
int	check_done(char *line)
{
	
}

int	check_args(char *line)
{
	
}

int	check_file_data(int ac, char **av)
{
	int		mapfd;
	char	*buffer;

	mapfd = open(av[1], O_RDONLY, 0644);
	while (1)
	{
		buffer = get_next_line(mapfd);
		if (!buffer)
			return (check_done(buffer));
		check_args(buffer);
		free(buffer);
	}
}

int	parser(int ac, char **av)
{
	if (!check_cub(ac, av))
		return (write(1, "Error\n> wrong file format\n", 26));
	if (!check_file_data(ac, av))
		return (write(1, "Error\n> invalid file data\n", 26));
}
