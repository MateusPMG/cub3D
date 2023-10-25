/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:15:33 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/25 16:57:14 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	free_data_p(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->texture[i])
			free(data->texture[i]);
		if (data->images[i])
		{
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
}

void	init_image(t_data *data)
{
	data->image.mlx_img = mlx_new_image(data->mlx_ptr, WINX, WINX);
	data->image.addr = (int *)mlx_get_data_addr(data->image.mlx_img,
			&data->image.bpp, &data->image.linelen, &data->image.endian);
}

void	get_images(t_data *data)
{
	int	h;
	int	i;

	h = 64;
	i = -1;
	while (++i < 4)
	{
		data->images[i] = ft_calloc(sizeof(t_img2), 1);
		data->images[i]->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
				data->texture[i], &h, &h);
		if (!data->images[i]->mlx_img)
		{
			print_error("invalid/empty texture");
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			free_data_p(data);
			exit (1);
		}
		data->images[i]->addr = 
			(int *)mlx_get_data_addr(data->images[i]->mlx_img,
				&data->images[i]->bpp, &data->images[i]->linelen,
				&data->images[i]->endian);
	}
	init_image(data);
}
