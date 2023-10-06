/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/06 15:23:54 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <X11/keysym.h>

# define WINX 1600
# define WINY 900

typedef struct s_data
{
	char	**map;
	int		c_floor;
	int		c_ceiling;
	char	*texture[4];
	size_t	map_x;
	size_t	map_y;
	int		gnl_x;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*images[4];

}	t_data;

//parser.c
int		parser(char **av, t_data *data);

//parser_utils.c
int		fill_text(t_data *data, char *line, int i, int index);
int		fill_colours(t_data *data, char *line, int i, int index);
int		check_done(t_data *data);
int		alloc_map(t_data *data, char **av);

//parser_utils_2.c
int		fill_map(char **av, t_data *data);
int		validate_map(t_data *data);
char	*skip_empty_lines(char *buffer, int *mapfd);
int		check_file_format(char **av, t_data *data);
int		return_free(char *buff);

//validate_map_utils.c
int		check_walls(t_data *data, int j, int i);

//utils.c
int		skip_spaces(char *str, int i);
int		print_error(char *str);
int		free_double(char **array);
int		free_data(t_data *data);

#endif