/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/19 16:33:32 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	**map;
	int		c_floor;
	int		c_ceiling;
	char	*texture[4];
	int		map_x;
	int		map_y;
	int		gnl_x;
	int		x;
	int		y;

}	t_data;

//parser.c
int		parser(char **av, t_data *data);

//parser_utils.c
int		fill_textures(t_data *data, char *line, int i, int index);
int		fill_colours(t_data *data, char *line, int i, int index);
int		check_done(t_data *data);
int		alloc_map(t_data *data, char **av);

//parser_utils_2.c
int		fill_map(char **av, t_data *data);
int		validate_map(t_data *data);

//validate_map_utils.c
int		check_walls(t_data *data, int j, int i);

//utils.c
int		skip_spaces(char *str, int i);
int		print_error(char *str);
int		free_double(char ***array);
int		free_data(t_data *data);

#endif