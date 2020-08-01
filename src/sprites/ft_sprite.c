/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:08:04 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 22:02:28 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_distance_sprite(t_param *param)
{
	int i;

	i = 0;
	while (i < param->sprite.num_sprites)
	{
		param->sprite.sprite_dis[i] = distance_between_points(
										param->player.x,
										param->player.y,
										param->sprite.sprite[i][1],
										param->sprite.sprite[i][0]);
		i++;
	}
}

float	ft_angle_middle_sprite(t_param *param, int n, float difference_angle)
{
	float	vectx_end;
	float	vecty_end;
	float	playerangle;
	float	spriteangle_end;
	float	wallspriteangle;

	vectx_end = (param->sprite.sprite[n][1] + param->sprite.sprite_stripheight)
				- param->player.x;
	vecty_end = (param->sprite.sprite[n][0] + param->sprite.sprite_stripheight)
				- param->player.y;
	playerangle = normalize_angle(param->player.rotation_angle);
	spriteangle_end = playerangle - atan2(vecty_end, vectx_end);
	if (spriteangle_end < -3.14159)
		spriteangle_end += 2.0 * 3.14159;
	if (spriteangle_end > 3.14159)
		spriteangle_end -= 2.0 * 3.14159;
	spriteangle_end = fabs(spriteangle_end);
	wallspriteangle = fabs(spriteangle_end - difference_angle);
	return (wallspriteangle);
}

float	ft_norm_diff_angle(float difference_angle)
{
	if (difference_angle < -3.14159)
		difference_angle += 2.0 * 3.14159;
	if (difference_angle > 3.14159)
		difference_angle -= 2.0 * 3.14159;
	difference_angle = fabs(difference_angle);
	return (difference_angle);
}

int		ft_sprite_visible(t_param *param, int n)
{
	int		visible;
	float	angle_player_sprite;
	float	difference_angle;
	float	fov_sprite;
	float	playerangle;

	param->sprite.spritex = param->sprite.sprite[n][1] -
		param->player.x;
	param->sprite.spritey = param->sprite.sprite[n][0] -
		param->player.y;
	angle_player_sprite = atan2(param->sprite.spritey,
			param->sprite.spritex);
	playerangle = normalize_angle(param->player.rotation_angle);
	difference_angle = playerangle - angle_player_sprite;
	difference_angle = ft_norm_diff_angle(difference_angle);
	fov_sprite = FOV_ANGLE / 2 +
				ft_angle_middle_sprite(param, n, difference_angle);
	if (difference_angle < fov_sprite)
		visible = 1;
	else
		visible = 0;
	return (visible);
}

void	ft_sprite(t_param *param)
{
	int n;

	n = 0;
	ft_distance_sprite(param);
	ft_sort_sprite(param);
	while (n < param->sprite.num_sprites)
	{
		param->sprite.sprite_stripheight = ((param->map.tile_size * 0.5) /
									param->sprite.sprite_dis[n]) *
									param->cast_all.dis_projection_plane;
		if (ft_sprite_visible(param, n) == 1)
		{
			ft_deal_sprite(param, n);
			ft_draw_sprite(param);
		}
		n++;
	}
}
