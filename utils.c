/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:37:36 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/06 15:14:54 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		free(data->texture[i]);
	free_double(data->map);
	free(data);
	return (0);
}
