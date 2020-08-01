/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:41 by user42            #+#    #+#             */
/*   Updated: 2020/08/01 14:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_color_texture_sprite(t_param *param, int x, int y)
{
	int d;
	int texture_offset_x;
	int texture_offset_y;
	int color;

	texture_offset_x = 0;
	texture_offset_y = 0;

	d = (y) * 256 - param->map.window_height * 128 +
		param->sprite.s_height * 128;
	texture_offset_x = (int)(256 *
			(x - (-param->sprite.s_width / 2 + param->sprite.s_screenx)) *
			param->tex[4].img_width / param->sprite.s_width) / 256;
	texture_offset_y = ((d * param->tex[4].img_height) / param->sprite.s_height)
						/ 256;
	
	if ((param->tex[4].img_width * texture_offset_y) +
			texture_offset_x <= param->tex[4].size_file)
		color = param->tex[4].data_text[(param->tex[4].img_width *
				texture_offset_y) + texture_offset_x];
	else
		color = 0xFFFFFF;
	return (color);
}

void	ft_draw_sprite(t_param *param)
{
	int x;
	int y;

	x = param->sprite.startx;
	while (x < param->sprite.endx)
	{
		y = param->sprite.starty;
		if (param->sprite.transformy > 0 &&
				x > 0 && x < param->map.window_width &&
				param->sprite.transformy < param->cast.buffer[x])
		{
			while (y < param->sprite.endy)
			{
				param->cast_all.color = ft_color_texture_sprite(param, x, y);
				if (param->cast_all.color != 0xFFFFFF && param->cast_all.color != 0x000000)
				{
					param->data[(param->map.window_width * y) + x] =
						param->cast_all.color;
				}
				y++;
			}
		}
		x++;
	}
}

void	ft_transform_sprite(t_param *param)
{
	float inv_det;

	inv_det = 1.0 / (param->player.planex * param->player.diry -
			param->player.dirx * param->player.planey);
	param->sprite.transformx = inv_det * (
			param->player.diry * param->sprite.spritex -
			param->player.dirx * param->sprite.spritey);
	param->sprite.transformy = inv_det * (
			-param->player.planey * param->sprite.spritex +
			param->player.planex * param->sprite.spritey);
	param->sprite.s_screenx = (int)(
			(param->map.window_width / 2) *
			(1 + -param->sprite.transformx / param->sprite.transformy));
	param->sprite.s_height = param->sprite.sprite_stripheight;
	param->sprite.s_width = param->sprite.s_height;
}

void	ft_sprite_top_bottom(t_param *param)
{
	param->sprite.starty = -param->sprite.s_height / 2 +
		param->map.window_height / 2;
	if (param->sprite.starty < 0)
		param->sprite.starty = 0;
	param->sprite.endy = param->sprite.s_height / 2 +
		param->map.window_height / 2;
	if (param->sprite.endy >= param->map.window_height)
		param->sprite.endy = param->map.window_height - 1;
	param->sprite.startx = -param->sprite.s_width / 2 +
		param->sprite.s_screenx;
	param->sprite.endx = param->sprite.s_width / 2 +
		param->sprite.s_screenx;
}

void	ft_deal_sprite(t_param *param, int number)
{
	ft_transform_sprite(param);
	ft_sprite_top_bottom(param);
}
