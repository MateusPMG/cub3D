/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:39:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/10/24 15:50:02 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"
# include <X11/keysym.h>
# include <math.h>

# define WINX 1600
# define WINY 900
# define MOVESPEED 0.1
# define ROTSPEED 0.05
# define TEXTUREWID	64

typedef struct s_img2
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_img2;

typedef struct s_cors
{
	int	x;
	int	y;

}	t_cors;

typedef struct s_cords
{
	double	x;
	double	y;
}	t_cords;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;
}	t_keys;

typedef struct s_data
{
	char	**map;
	int		c_floor;
	int		c_ceiling;
	char	*texture[4];
	int		**buffer;
	t_keys	key_states;
	size_t	map_x;
	size_t	map_y;
	int		gnl_x;
	t_cors	m_pos;
	t_cords	pos;
	t_cords	cplane;
	t_cords	dirv;
	t_cords	cam;
	t_cords	rayd;
	t_cords	delta;
	t_cords	sidedis;
	t_cors	step;
	t_cors	tex;
	double	winstep;
	double	tex_pos;
	double	wallx;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img2	*images[4];
	t_img2	image;

}	t_data;

//parser.c
int		parser(char **av, t_data *data);

//parser_utils.c
int		fill_text(t_data *data, char *line, int i, int index);
int		fill_colours(t_data *data, char *line, int i, int index);
int		check_done(t_data *data);
int		alloc_map(t_data *data, char **av);

//parser_utils_2.c
int		fill_map(char **av, t_data *data);
int		validate_map(t_data *data);
char	*skip_empty_lines(char *buffer, int *mapfd);
int		check_file_format(char **av, t_data *data);
int		return_free(char *buff);

//validate_map_utils.c
int		check_walls(t_data *data, int j, int i);

//images.c
void	get_images(t_data *data);

//ray_casting.c
int		ray_init(t_data *data);
void	ray_cast(t_data *data);


//ray_casting_utils.c
void	dirv_init(t_data *data);
void	cplane_init(t_data *data);
void	step_d(t_data *data);
void	dda(t_data *data);
void	cam_cal(t_data *data, int x);

//ray_casting_utils_2.c
void	color_map(t_data *data, int x);
int		game_loop(t_data *data);

//movement.c
void	movement(t_data *data);

//utils.c
int		skip_spaces(char *str, int i);
int		print_error(char *str);
int		free_double(char **array);
int		free_data(t_data *data);
int		close_window(t_data *data);


#endif