/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/10 14:31:20 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit(1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (WINX),
			(WINY), "cub3D");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(1);
	}
	get_images(data);
	casting();
	mlx_hook(data->win_ptr, 17, 1L << 17, close_handler, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_handler, data);
	mlx_loop(data->mlx_ptr);
	return ;
}

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
	int		i;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (ac != 2)
	{
		free_data(data);
		return (write(1, "Error\n-Wrong number of args\n", 28));
	}
	init_data(data);
	if (parser(av, data))
	{
		free_data(data);
		return (1);
	}
	i = -1;
	while (data->map[++i])
		printf(":%s:\n", data->map[i]);
	mlx(data);
	mlx_destroy_image(data->mlx_ptr, data->image.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_data(data);
	return (0);
}
