/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:29:02 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/18 17:27:51 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ray_init(t_data *data)
{
	data->pos.x = data->m_pos.x + 0.5;
	data->pos.y = data->m_pos.y + 0.5;
	dirv_init(data);
	cplane_init(data);
	return (0);
}

void	ray_cast(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WINX)
	{
		data->cam.x = (2 * x) / ((double)WINX - 1);
		data->rayd.x = (data->dirv.x) + (data->cplane.x * data->cam.x);
		data->rayd.y = (data->dirv.y) + (data->cplane.y * data->cam.x);
		/* data->m_pos.x = (int)data->pos.x;
		data->m_pos.y = (int)data->pos.y; */
		if (data->rayd.x != 0)
			data->delta.x = fabs(1 / data->rayd.x);
		else
			data->delta.x = pow(10, 30);
		if (data->rayd.y != 0)
			data->delta.y = fabs(1 / data->rayd.y);
		else
			data->delta.y = pow(10, 30);
		step_d(data);
		dda(data);
		cam_cal(data, x);
	}
}
