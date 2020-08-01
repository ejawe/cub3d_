/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horz_vert_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:10 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 22:15:05 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_increment_horz_step(t_param *param)
{
	float x_to_check;
	float y_to_check;
	float limite_y;

	limite_y = (param->infomap.nb_line_map - 1) * param->map.tile_size;
	while (param->cast.next_horztouchx >= 0 && param->cast.next_horztouchx <=
			param->map.window_width && param->cast.next_horztouchy >= 0 &&
			param->cast.next_horztouchy <= limite_y)
	{
		x_to_check = param->cast.next_horztouchx;
		y_to_check = param->cast.next_horztouchy +
					(param->rays.is_rayfacing_up ? -1 : 0);
		if (map_has_wall_at(x_to_check, y_to_check, param) == 1)
		{
			param->cast.found_horzwallhit = 1;
			param->cast.horz_wallhitx = param->cast.next_horztouchx;
			param->cast.horz_wallhity = param->cast.next_horztouchy;
			break ;
		}
		else
		{
			param->cast.next_horztouchx += param->cast.xstep;
			param->cast.next_horztouchy += param->cast.ystep;
		}
	}
}

void	ft_horizontal_intersection(t_param *param, float ray_angle)
{
	param->cast.yintercept = floor(param->player.y / param->map.tile_size) *
							param->map.tile_size;
	if (param->rays.is_rayfacing_down)
		param->cast.yintercept += param->map.tile_size;
	param->cast.xintercept = param->player.x +
		((param->cast.yintercept - param->player.y) / tan(ray_angle));
	param->cast.ystep = param->map.tile_size;
	if (param->rays.is_rayfacing_up)
		param->cast.ystep *= -1;
	param->cast.xstep = param->map.tile_size / tan(ray_angle);
	if (param->rays.is_rayfacing_left && param->cast.xstep > 0)
		param->cast.xstep *= -1;
	if (param->rays.is_rayfacing_right && param->cast.xstep < 0)
		param->cast.xstep *= -1;
	param->cast.next_horztouchx = param->cast.xintercept;
	param->cast.next_horztouchy = param->cast.yintercept;
	ft_increment_horz_step(param);
}

void	ft_increment_vert_step(t_param *param)
{
	float x_to_check;
	float y_to_check;
	float limite_y;

	limite_y = (param->infomap.nb_line_map - 1) * param->map.tile_size;
	while (param->cast.next_verttouchx >= 0 && param->cast.next_verttouchx <=
			param->map.window_width && param->cast.next_verttouchy >= 0 &&
			param->cast.next_verttouchy <= limite_y)
	{
		x_to_check = param->cast.next_verttouchx +
					(param->rays.is_rayfacing_left ? -1 : 0);
		y_to_check = param->cast.next_verttouchy;
		if (map_has_wall_at(x_to_check, y_to_check, param) == 1)
		{
			param->cast.found_vertwallhit = 1;
			param->cast.vert_wallhitx = param->cast.next_verttouchx;
			param->cast.vert_wallhity = param->cast.next_verttouchy;
			break ;
		}
		else
		{
			param->cast.next_verttouchx += param->cast.xstep;
			param->cast.next_verttouchy += param->cast.ystep;
		}
	}
}

void	ft_vertical_intersection(t_param *param, float ray_angle)
{
	param->cast.xintercept = floor(param->player.x / param->map.tile_size) *
							param->map.tile_size;
	if (param->rays.is_rayfacing_right)
		param->cast.xintercept += param->map.tile_size;
	param->cast.yintercept = param->player.y +
		(param->cast.xintercept - param->player.x) * tan(ray_angle);
	param->cast.xstep = param->map.tile_size;
	if (param->rays.is_rayfacing_left)
		param->cast.xstep *= -1;
	param->cast.ystep = param->map.tile_size * tan(ray_angle);
	if (param->rays.is_rayfacing_up && param->cast.ystep > 0)
		param->cast.ystep *= -1;
	if (param->rays.is_rayfacing_down && param->cast.ystep < 0)
		param->cast.ystep *= -1;
	param->cast.next_verttouchx = param->cast.xintercept;
	param->cast.next_verttouchy = param->cast.yintercept;
	ft_increment_vert_step(param);
}

void	ft_horz_vert_intersection(t_param *param, float ray_angle)
{
	ft_horizontal_intersection(param, ray_angle);
	ft_vertical_intersection(param, ray_angle);
}
