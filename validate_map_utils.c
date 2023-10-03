/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:08:33 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/03 13:57:43 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	walkable(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '0')
		return (1);
	return (0);
}

int	check_walls(t_data *data, int j, int i)
{
	size_t	a;
	size_t	b;
	size_t	c;
	size_t	d;

	a = i;
	while (a > 0 && (a < data->map_y - 1 && data->map[++a][j])
		&& walkable(data->map[a][j]))
		continue ;
	b = i;
	while (b > 0 && data->map[--b][j] && walkable(data->map[b][j]))
		continue ;
	c = j;
	while (c > 0 && data->map[i][++c] && walkable(data->map[i][c]))
		continue ;
	d = j;

	while (d > 0 && data->map[i][--d] && walkable(data->map[i][d]))
		continue ;
	if (!data->map[i][d] || !data->map[i][c] || !data->map[b][j]
		|| !data->map[a][j] || data->map[i][d] != '1'
		|| data->map[i][c] != '1' || data->map[b][j] != '1'
		|| (a == data->map_y - 1 && data->map[a][j] != '1'))
		return (1);
	return (0);
}
