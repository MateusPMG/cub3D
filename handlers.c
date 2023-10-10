/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:28:52 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/10 13:45:36 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_A)
		printf("%s\n", "pressed a");
	if (keycode == XK_W)
		printf("%s\n", "pressed w");
	if (keycode == XK_D)
		printf("%s\n", "pressed d");
	if (keycode == XK_S)
		printf("%s\n", "pressed s");
	return (1);
}

int	close_handler(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}
