/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/26 15:12:38 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data *data)
{
	data->c_ceiling = -1;
	data->c_floor = -1;
	data->gnl_x = 0;
	data->map_x = 0;
	data->x = -1;
	data->y = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (ac != 2)
	{
		free_data(data);
		return (write(1, "Error\n-Wrong number of args\n", 28));
	}
	init_data(data);
	if (!parser(av, data))
		free_data(data);
}
