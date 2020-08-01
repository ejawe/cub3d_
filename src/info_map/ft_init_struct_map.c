/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:15 by user42            #+#    #+#             */
/*   Updated: 2020/07/31 14:20:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_init_struct_text(t_param *param)
{
	int i;

	i = 0;
	while (i < NUM_TEX)
	{
		param->tex[i].img_file = NULL;
		param->tex[i].path_file = NULL;
		param->tex[i].img_width = 0;
		param->tex[i].img_height = 0;
		param->tex[i].data_text = 0;
		i++;
	}
}

void	ft_init_struct_map(t_param *param)
{
	param->infomap.reso_x = 0;
	param->infomap.reso_y = 0;
	ft_bzero(param->infomap.f_rgb, sizeof(int));
	ft_bzero(param->infomap.c_rgb, sizeof(int));
	param->infomap.tabmap = NULL;
	param->infomap.position_map = 0;
	param->infomap.string = NULL;
	param->infomap.nb_line_map = 0;
	param->map.num_cols = 0;
	param->map.tile_size = 0;
	param->map.wall_strip_width = 1;
	param->map.num_rays = 0;
	param->map.window_width = 0;
	param->map.window_height = 0;
	param->infomap.tabmap = NULL;
	param->mlx_ptr = NULL;
	param->sprite.sprite = 0;
	param->sprite.sprite_dis = 0;
	param->cast.buffer = 0;
	ft_init_struct_text(param);
}
