/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:15:33 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/17 15:45:30 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		data->images[i]->addr = 
			(int *)mlx_get_data_addr(data->images[i]->mlx_img,
				&data->images[i]->bpp, &data->images[i]->linelen,
				&data->images[i]->endian);
	}
	init_image(data);
}
