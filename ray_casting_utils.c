/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:53:01 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/11 16:42:30 by mpatrao          ###   ########.fr       */
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
		data->side.x = (data->pos.x - data->m_pos.x) * data->delta.x;
	}
	else
	{
		data->step.x = 1;
		data->side.x = (data->m_pos.x + 1 - data->pos.x) * data->delta.x;
	}
	if (data->rayd.y < 0)
	{
		data->step.y = -1;
		data->side.y = (data->pos.y - data->m_pos.y) * data->delta.y;
	}
	else
	{
		data->step.y = 1;
		data->side.y = (data->m_pos.y + 1 - data->pos.y) * data->delta.y;
	}
}
