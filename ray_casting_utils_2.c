/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:47:34 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/18 14:20:36 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_pixel(t_img2 img, int x, int y)
{
	return (y * (img.linelen / 4) + x);
}

int	pick_tex(t_data *data)
{
	if (data->side == 0)
	{
		if ((double)data->m_pos.x - data->pos.x > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if ((double)data->m_pos.y - data->pos.y > 0)
			return (2);
		else
			return (3);
	}
}

void	color_map(t_data *data, int x)
{
	int	y;
	int	color;
	int	tex_num;

	tex_num = pick_tex(data);
	y = data->drawstart;
	while (y < data->drawend)
	{
		if (data->tex_pos > (double)INT_MAX)
			data->tex.y = INT_MAX;
		else
			data->tex.y = (int)data->tex_pos;
		data->tex_pos += data->winstep;
		color = data->images[tex_num]->addr[TEXTUREWID * data->tex.y
			+ data->tex.x];
		if (!color)
			color++;
		data->image.addr[get_pixel(data->image, x, y)] = color;
		y++;
	}
}

void	color_ceiling_floor(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < WINY)
	{
		i = -1;
		while (++i < WINX)
		{
			if (j < (WINY / 2))
				data->image.addr[get_pixel(data->image, i, j)]
					= data->c_ceiling;
			else 
				data->image.addr[get_pixel(data->image, i, j)]
					= data->c_floor;
		}
	}
}

int	game_loop(t_data *data)
{
	color_ceiling_floor(data);
	ray_cast(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.mlx_img,
		0, 0);
	return (0);
}
