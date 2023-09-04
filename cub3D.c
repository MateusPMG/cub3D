/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/09/04 15:17:22 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data *data)
{
	data->c_ceiling = -1;
	data->c_floor = -1;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (write(1, "Error\n-Wrong number of args", 27));
	init_data(data);
	if (!parser(ac, av, data))
	{
		printf();
		free_data();
	}
}
