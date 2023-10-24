/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:37:36 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/24 17:05:56 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	skip_spaces(char *str, int i)
{
	while (str[i] && ft_isspace(i))
		i++;
	return (i);
}

int	print_error(char *str)
{
	printf("Error\n> %s\n", str);
	return (1);
}

int	free_double(char **array)
{
	int	i;

	if (!(array))
		return (1);
	i = -1;
	while ((array)[++i])
	{
		if ((array)[i])
			free((array)[i]);
	}
	free(array);
	return (1);
}

int	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->texture[i])
			free(data->texture[i]);
		if (data->images[i])
		{
			mlx_destroy_image(data->mlx_ptr, data->images[i]->mlx_img);
			free(data->images[i]);
		}
	}
	if (data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_double(data->map);
	free(data);
	return (0);
}
