/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:11 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:08:18 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_floor(t_param *param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param->map.window_height / 2)
	{
		while (j < param->map.window_width)
		{
			param->data[(i + param->map.window_height / 2) *
			param->map.window_width + (j + 0)] = param->infomap.f_color;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_ceiling(t_param *param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < param->map.window_height / 2)
	{
		while (j < param->map.window_width)
		{
			param->data[(i + 0) * param->map.window_width + (j + 0)] =
			param->infomap.c_color;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_floor_ceiling(t_param *param)
{
	ft_floor(param);
	ft_ceiling(param);
}
