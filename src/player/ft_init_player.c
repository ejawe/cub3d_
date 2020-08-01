/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:06:04 by user42            #+#    #+#             */
/*   Updated: 2020/07/31 13:57:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_position_player(t_param *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->infomap.nb_line_map)
	{
		j = 0;
		while (param->infomap.tabmap[i][j] != '\0')
		{
			if (param->infomap.tabmap[i][j] == 'N' ||
					param->infomap.tabmap[i][j] == 'S' ||
					param->infomap.tabmap[i][j] == 'E' ||
					param->infomap.tabmap[i][j] == 'W')
			{
				param->player.x = j * param->map.tile_size +
					(param->map.tile_size / 2);
				param->player.y = i * param->map.tile_size +
					(param->map.tile_size / 2);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_player(t_param *param)
{
	param->player.width = 5;
	param->player.height = 5;
	param->player.turn_direction = 0;
	param->player.walk_direction = 0;
	if (param->map.window_width < 500 || param->map.window_height < 500)
	{
		param->player.walk_speed = 1;
		param->player.turn_speed = 1 * (M_PI / 180);
	}
	else
	{
		param->player.walk_speed = 4;
		param->player.turn_speed = 4 * (M_PI / 180);
	}
	param->player.side = 0;
	ft_orientation(param);
	ft_position_player(param);
}
