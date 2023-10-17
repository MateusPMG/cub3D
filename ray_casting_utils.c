/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:53:01 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/17 15:49:48 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dirv_init(t_data *data)
{
	if (data->map[data->m_pos.y][data->m_pos.x] == 'N')
	{
		data->dirv.x = 0;
		data->dirv.y = -1;
	}
	else if (data->map[data->m_pos.y][data->m_pos.x] == 'S')
	{
		data->dirv.x = 0;
		data->dirv.y = 1;
	}
	else if (data->map[data->m_pos.y][data->m_pos.x] == 'W')
	{
		data->dirv.x = -1;
		data->dirv.y = 0;
	}
	else if (data->map[data->m_pos.y][data->m_pos.x] == 'E')
	{
		data->dirv.x = 1;
		data->dirv.y = 0;
	}
}

void	cplane_init(t_data *data)
{
	if (data->dirv.x == 0 && data->dirv.y == -1)
	{
		data->cplane.x = 0.66;
		data->cplane.y = 0;
	}
	else if (data->dirv.x == 0 && data->dirv.y == 1)
	{
		data->cplane.x = -0.66;
		data->cplane.y = 0;
	}
	else if (data->dirv.x == -1 && data->dirv.y == 0)
	{
		data->cplane.x = 0;
		data->cplane.y = -0.66;
	}
	else if (data->dirv.x == 1 && data->dirv.y == 0)
	{
		data->cplane.x = 0;
		data->cplane.y = 0.66;
	}
}

void	step_d(t_data *data)
{
	if (data->rayd.x < 0)
	{
		data->step.x = -1;
		data->sidedis.x = (data->pos.x - data->m_pos.x) * data->delta.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedis.x = (data->m_pos.x + 1 - data->pos.x) * data->delta.x;
	}
	if (data->rayd.y < 0)
	{
		data->step.y = -1;
		data->sidedis.y = (data->pos.y - data->m_pos.y) * data->delta.y;
	}
	else
	{
		data->step.y = 1;
		data->sidedis.y = (data->m_pos.y + 1 - data->pos.y) * data->delta.y;
	}
}

void	dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedis.x < data->sidedis.y)
		{
			data->sidedis.x += data->delta.x;
			data->m_pos.x += data->step.x;
			data->side = 0;
		}
		else
		{
			data->sidedis.y += data->delta.y;
			data->m_pos.y += data->step.y;
			data->side = 1;
		}
	}
	if (data->map[data->m_pos.y][data->m_pos.x] == '1')
		data->hit = 1;
}

void	cam_cal(t_data *data, int x)
{
	if (data->side == 0)
		data->perpwalldist = (data->sidedis.x - data->delta.x);
	else
		data->perpwalldist = (data->sidedis.y - data->delta.y);
	data->lineheight = (WINY / data->perpwalldist);
	data->drawstart = (-data->lineheight / 2) + (WINY / 2);
	data->drawend = (data->lineheight / 2) + (WINY / 2);
	if (data->drawstart < 0)
		data->drawstart = 0;
	if (data->drawend >= WINY)
		data->drawend = WINY - 1;
	if (data->side == 0)
		data->wallx = data->pos.y + (data->perpwalldist * data->rayd.y);
	else
		data->wallx = data->pos.x + (data->perpwalldist * data->rayd.x);
	data->wallx -= (int)data->wallx;
	data->tex.x = (int)(data->wallx * TEXTUREWID);
	if ((data->side == 0 && data->rayd.x > 0)
		|| (data->side == 1 && data->rayd.y < 0))
		data->tex.x = TEXTUREWID - data->tex.x - 1;
	data->winstep = (1.0 * TEXTUREWID) / (data->lineheight);
	data->tex_pos = (data->drawstart + ((-WINY + data->lineheight) / 2)) 
		* data->winstep;
	color_map(data, x);
}
