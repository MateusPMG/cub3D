/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:29:02 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/13 14:29:11 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ray_init(t_data *data)
{
	data->pos.x = data->m_pos.x + 0.5;
	data->pos.y = data->m_pos.y + 0.5;
	dirv_init(data);
	cplane_init(data);
	/* printf("%f\n%f\n%f\n%f\n%f\n%f\n", data->pos.x, data->pos.y, data->dirv.x,
		data->dirv.y, data->cplane.x, data->cplane.y); */
	return (0);
}

int	ray_cast(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WINX)
	{
		data->cam.x = (2 * x) / ((double)WINX - 1);
		data->rayd.x = (data->dirv.x) + (data->cplane.x) + (data->cam.x);
		data->rayd.y = (data->dirv.y) + (data->cplane.y) + (data->cam.x);
		data->delta.x = fabs(1 / data->rayd.x);
		data->delta.y = fabs(1 / data->rayd.y);
		step_d(data);
		dda(data);
		cam_cal(data);
		redraw();
		cls();
	}
}
