/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:46:16 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/18 16:28:19 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	move(t_data *data, int flag, t_cords cam_dir)
{
	t_cords	new;

	new.x = (data->pos.x + cam_dir.x * MOVESPEED * flag);
	new.y = (data->pos.y + cam_dir.y * MOVESPEED * flag);
	if (data->map[(int)data->pos.y][(int)new.x] != '1')
	{
		data->pos.x = new.x;
		data->m_pos.x = data->pos.x;
	}
	if (data->map[(int)new.y][(int)data->pos.x] != '1')
	{
		data->pos.y = new.y;
		data->m_pos.y = data->pos.y;
	}
	return (0);
}

int	rotate(t_data *data, double rot_speed)
{
	double	old_dir;
	double	old_cam;

	old_dir = data->dirv.x;
	data->dirv.x = data->dirv.x * cos(rot_speed) \
		- data->dirv.y * sin(rot_speed);
	data->dirv.y = old_dir * sin(rot_speed) \
		+ data->dirv.y * cos(rot_speed);
	old_cam = data->cplane.x;
	data->cplane.x = data->cplane.x * cos(rot_speed) \
		- data->cplane.y * sin(rot_speed);
	data->cplane.y = old_cam * sin(rot_speed) \
		+ data->cplane.y * cos(rot_speed);
	return (0);
}

void	movement(t_data *data)
{
	if (data->key_states.w)
		move(data, 1, data->dirv);
	if (data->key_states.s)
		move(data, -1, data->dirv);
	if (data->key_states.a)
		move(data, -1, data->cplane);
	if (data->key_states.d)
		move(data, 1, data->cplane);
	if (data->key_states.l)
		rotate(data, -ROTSPEED);
	if (data->key_states.r)
		rotate(data, ROTSPEED);
	return ;
}
