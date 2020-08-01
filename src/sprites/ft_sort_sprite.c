/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:08:04 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 21:52:19 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_sort(t_param *param, int i, int j)
{
	float	temp_y;
	float	temp_x;
	float	temp_distance;

	temp_distance = param->sprite.sprite_dis[j];
	param->sprite.sprite_dis[j] = param->sprite.sprite_dis[i];
	param->sprite.sprite_dis[i] = temp_distance;
	temp_x = param->sprite.sprite[j][1];
	temp_y = param->sprite.sprite[j][0];
	param->sprite.sprite[j][1] = param->sprite.sprite[i][1];
	param->sprite.sprite[j][0] = param->sprite.sprite[i][0];
	param->sprite.sprite[i][1] = temp_x;
	param->sprite.sprite[i][0] = temp_y;
}

void	ft_sort_sprite(t_param *param)
{
	int		i;
	int		j;

	i = 0;
	while (i < param->sprite.num_sprites)
	{
		j = i + 1;
		while (j < param->sprite.num_sprites)
		{
			if (param->sprite.sprite_dis[j] >
				param->sprite.sprite_dis[i])
				ft_sort(param, i, j);
			j++;
		}
		i++;
	}
}
