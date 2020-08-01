/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:17 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:10:44 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_render_player(t_param *param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param->player.height * MINIMAP_SCALE_FACTOR)
	{
		while (j < param->player.width * MINIMAP_SCALE_FACTOR)
		{
			param->data[
				(i + (int)(param->player.y * MINIMAP_SCALE_FACTOR)) *
				param->map.window_width +
				(j + (int)(param->player.x * MINIMAP_SCALE_FACTOR))] = 0xFF0000;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_bloc(t_param *param, int i, int j, int color)
{
	int k;
	int l;

	k = 0;
	l = 0;
	param->map.lx = j * param->map.tile_size * MINIMAP_SCALE_FACTOR;
	param->map.ly = i * param->map.tile_size * MINIMAP_SCALE_FACTOR;
	while (l < param->map.tile_size * MINIMAP_SCALE_FACTOR)
	{
		while (k < param->map.tile_size * MINIMAP_SCALE_FACTOR)
		{
			param->data[param->map.ly * param->map.window_width +
						param->map.lx] = color;
			param->map.lx++;
			k++;
		}
		param->map.lx = j * param->map.tile_size * MINIMAP_SCALE_FACTOR;
		param->map.ly++;
		k = 0;
		l++;
	}
}

void	ft_render_map(t_param *param)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	param->map.lx = 0;
	param->map.ly = 0;
	while (i < param->infomap.nb_line_map)
	{
		j = 0;
		while (param->infomap.tabmap[i][j] != '\0')
		{
			if (param->infomap.tabmap[i][j] == '1')
				color = 0xFFFFFF;
			if (param->infomap.tabmap[i][j] != '1')
				color = 0x000000;
			ft_draw_bloc(param, i, j, color);
			j++;
		}
		i++;
	}
}
