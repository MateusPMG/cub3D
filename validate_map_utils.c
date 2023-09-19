/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:08:33 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/19 17:17:52 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	walkable(char c)
{
	
}

int	check_walls(t_data *data, int j, int i)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = i;
	while (a > 0 && data->map[++a][j] && walkable(data->map[a][j]))
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
	if ()
		return (1);
	return (0);
}
