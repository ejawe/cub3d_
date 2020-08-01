/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:50 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 13:50:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		map_has_wall_at(float x, float y, t_param *param)
{
	int map_gridx;
	int map_gridy;

	map_gridx = floor(x / param->map.tile_size);
	map_gridy = floor(y / param->map.tile_size);
	if (map_gridx < 0 || map_gridx > param->map.num_cols ||
	map_gridy < 0 || map_gridy > param->infomap.nb_line_map)
		return (0);
	if (param->infomap.tabmap[map_gridy][map_gridx] == '1')
		return (1);
	return (0);
}
