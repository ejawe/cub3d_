/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:04 by user42            #+#    #+#             */
/*   Updated: 2020/08/01 16:47:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_malloc_tab_distance(t_param *param, int error)
{
	int i;

	i = 0;
	if (!(param->cast.buffer =
	(float *)malloc(sizeof(float) * param->map.num_rays)))
		error = 15;
	while (i < param->map.num_rays)
	{
		param->cast.buffer[i] = 0.0;
		i++;
	}
	return (error);
}

void	ft_screen_size(t_param *param)
{
	int sizex;
	int sizey;

	sizex = 0;
	sizey = 0;
	mlx_get_screen_size(param->mlx_ptr, &sizex, &sizey);
	if (param->map.window_width > sizex)
		param->map.window_width = (unsigned int)sizex;
	if (param->map.window_height > sizey)
		param->map.window_height = (unsigned int)sizey;
	param->infomap.reso_x = param->map.window_width;
	param->infomap.reso_y = param->map.window_height;
	param->map.num_rays = param->infomap.reso_x / param->map.wall_strip_width;
	param->map.tile_size = param->infomap.reso_x / param->map.num_cols;
	printf("sizex = %d  -  sizey = %d  -  window_width = %d  -  window_height = %d\n", sizex, sizey, param->map.window_width, param->map.window_height);
}

int		ft_init_game(t_param *param)
{
	int error;

	error = 0;
	if (!(param->mlx_ptr = mlx_init()))
		error = 16;
	ft_screen_size(param);
	if (!(param->win_ptr = mlx_new_window(
							param->mlx_ptr,
							param->map.window_width,
							param->map.window_height,
							"Cub3D")))
		error = 16;
	error = ft_malloc_tab_distance(param, error);
	ft_init_player(param);
	ft_init_texture(param);
	ft_init_sprite(param);
	if (error != 0)
		ft_free_all(param, error);
	return (0);
}
