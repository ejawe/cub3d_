/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:55 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 21:52:29 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_init_struct_sprite(t_param *param)
{
	param->sprite.x = 0;
	param->sprite.y = 0;
	param->sprite.num_sprites = 0;
	param->sprite.sprite = 0;
	param->sprite.sprite_dis = 0;
}

void	ft_num_sprites(t_param *param)
{
	int i;
	int j;

	i = 0;
	while (i < param->infomap.nb_line_map)
	{
		j = 0;
		while (param->infomap.tabmap[i][j] != '\0')
		{
			if (param->infomap.tabmap[i][j] == '2')
				param->sprite.num_sprites++;
			j++;
		}
		i++;
	}
}

int		ft_malloc_sprite(t_param *param)
{
	int i;

	i = 0;
	if (!(param->sprite.sprite =
			(float**)malloc(sizeof(float *) * param->sprite.num_sprites)))
		return (0);
	while (i < param->sprite.num_sprites)
	{
		if (!(param->sprite.sprite[i] = (float *)malloc(sizeof(float) * 2)))
			return (0);
		i++;
	}
	if (!(param->sprite.sprite_dis =
			(float *)malloc(sizeof(float) * param->sprite.num_sprites)))
		return (0);
	return (0);
}

void	ft_coordinate_sprite(t_param *param)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < param->infomap.nb_line_map)
	{
		j = 0;
		while (param->infomap.tabmap[i][j] != '\0')
		{
			if (param->infomap.tabmap[i][j] == '2')
			{
				param->sprite.sprite[k][0] = i * param->map.tile_size +
											(param->map.tile_size / 2);
				param->sprite.sprite[k][1] = j * param->map.tile_size +
											(param->map.tile_size / 2);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_sprite(t_param *param)
{
	ft_init_struct_sprite(param);
	ft_num_sprites(param);
	ft_malloc_sprite(param);
	ft_coordinate_sprite(param);
}
