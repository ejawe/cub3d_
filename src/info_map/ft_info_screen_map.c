/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_screen_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:09 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 14:33:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_info_screen_map(t_param *param)
{
	int i;
	int len;

	i = 0;
	while (param->infomap.string[i])
	{
		len = 0;
		while (param->infomap.string[i] != '.')
		{
			len++;
			i++;
		}
		if (len > param->map.num_cols)
			param->map.num_cols = len;
		i++;
	}
	param->map.window_width = param->infomap.reso_x;
	param->map.window_height = param->infomap.reso_y;
	param->map.wall_strip_width = 1;
	param->map.num_rays = param->infomap.reso_x / param->map.wall_strip_width;
	param->map.tile_size = param->infomap.reso_x / param->map.num_cols;
}
