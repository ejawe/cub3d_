/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:58 by user42            #+#    #+#             */
/*   Updated: 2020/07/28 12:00:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_move_camera(t_param *param)
{
	float old_dir_x;
	float old_plane_x;
	float rt;

	rt = param->player.turn_direction * param->player.turn_speed;
	old_dir_x = param->player.dirx;
	param->player.dirx = param->player.dirx * cos(rt) -
							param->player.diry * sin(rt);
	param->player.diry = old_dir_x * sin(rt) + param->player.diry * cos(rt);
	old_plane_x = param->player.planex;
	param->player.planex = param->player.planex * cos(rt) -
							param->player.planey * sin(rt);
	param->player.planey = old_plane_x * sin(rt) +
							param->player.planey * cos(rt);
}

int		ft_playerdirection(t_param *param, float rotation_angle)
{
	float	angle;
	int		is_vertical;

	is_vertical = 0;
	angle = normalize_angle(rotation_angle);
	if ((angle > M_PI * 0.25 && angle < 0.75 * M_PI) ||
	(angle > M_PI * 1.25 && angle < 1.75 * M_PI))
		is_vertical = 1;
	else
		is_vertical = 0;
	return (is_vertical);
}

void	ft_new_player(float move_step, t_param *param)
{
	float	is_vertical;
	float	new_angle;

	is_vertical = ft_playerdirection(param, param->player.rotation_angle);
	new_angle = (M_PI * 0.5) - param->player.rotation_angle;
	if (is_vertical == 0 && param->player.side == 1)
	{
		param->player.newx = param->player.x - cos(new_angle) * move_step;
		param->player.newy = param->player.y + sin(new_angle) * move_step;
	}
	else if (is_vertical == 1 && param->player.side == 1)
	{
		param->player.newx = param->player.x + cos(new_angle) * -move_step;
		param->player.newy = param->player.y - sin(new_angle) * -move_step;
	}
	else if (param->player.side == 0)
	{
		param->player.newx = param->player.x +
				cos(param->player.rotation_angle) * move_step;
		param->player.newy = param->player.y +
				sin(param->player.rotation_angle) * move_step;
	}
}

void	ft_move_player(t_param *param)
{
	float	move_step;

	param->player.rotation_angle +=
			param->player.turn_direction * param->player.turn_speed;
	move_step = param->player.walk_direction * param->player.walk_speed;
	ft_new_player(move_step, param);
	ft_move_camera(param);
	if (map_has_wall_at(param->player.newx, param->player.newy, param) == 0)
	{
		param->player.x = param->player.newx;
		param->player.y = param->player.newy;
	}
}
