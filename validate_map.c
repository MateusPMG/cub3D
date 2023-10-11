/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:57:42 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/11 15:25:12 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	add_spaces(t_data *data, int j)
{
	while (ft_strlen(data->map[j]) < data->map_x)
		data->map[j] = ft_strjoin_free(data->map[j], " ");
}

int	rectify_shape(t_data *data)
{
	int	i;
	int	j;

	i = data->map_y;
	j = 0;
	while (i >= 0 && data->map[j])
	{
		if (ft_strlen(data->map[j]) < data->map_x)
			add_spaces(data, j);
		i--;
		j++;
	}
	return (0);
}

int	check_illegal(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'W' && c != 'E'
		&& c != ' ')
		return (1);
	return (0);
}

int	check_dupe(char c, t_data *data, size_t i, size_t j)
{
	int	a;
	int	b;

	a = data->map_x;
	b = data->map_y;
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E')
		&& (data->m_pos.x == -1 && data->m_pos.y == -1))
	{
		data->m_pos.x = j;
		data->m_pos.y = i;
	}
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E')
		&& ((data->m_pos.x != -1 && data->m_pos.y != -1)
			|| (data->m_pos.x == 0 || data->m_pos.x == a
				|| data->m_pos.y == b || data->m_pos.y == 0)))
		return (1);
	return (0);
}

int	validate_map(t_data *data)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	rectify_shape(data);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (check_illegal(data->map[i][j])
				|| check_dupe(data->map[i][j], data, i, j))
				return (print_error("illegal char in map or char duped"));
			if (data->map[i][j] == '0')
				if (check_walls(data, j, i))
					return (print_error("invalid map: unclosed/illegal char"));
			j++;
		}
		i++;
	}
	if (data->m_pos.x == -1)
		return (print_error("missing spawn"));
	return (0);
}
