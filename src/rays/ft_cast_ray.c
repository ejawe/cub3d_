/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:06:34 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 22:15:00 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_ray_facing(t_param *param, float ray_angle)
{
	if (ray_angle > 0 && ray_angle < M_PI)
		param->rays.is_rayfacing_down = 1;
	else
		param->rays.is_rayfacing_up = 1;
	if (ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI))
		param->rays.is_rayfacing_right = 1;
	else
		param->rays.is_rayfacing_left = 1;
}

void	ft_clother_distance(t_param *param)
{
	if (param->cast.found_horzwallhit == 1)
		param->cast.horz_hit_distance = distance_between_points(param->player.x,
		param->player.y, param->cast.horz_wallhitx, param->cast.horz_wallhity);
	else
		param->cast.horz_hit_distance = 2147483647;
	if (param->cast.found_vertwallhit == 1)
		param->cast.vert_hit_distance = distance_between_points(param->player.x,
		param->player.y, param->cast.vert_wallhitx, param->cast.vert_wallhity);
	else
		param->cast.vert_hit_distance = 2147483647;
	if (param->cast.horz_hit_distance < param->cast.vert_hit_distance)
	{
		param->rays.wall_hitx = param->cast.horz_wallhitx;
		param->rays.wall_hity = param->cast.horz_wallhity;
		param->rays.distance = param->cast.horz_hit_distance;
	}
	else
	{
		param->rays.wall_hitx = param->cast.vert_wallhitx;
		param->rays.wall_hity = param->cast.vert_wallhity;
		param->rays.distance = param->cast.vert_hit_distance;
	}
}

void	ft_cast_ray(float ray_angle, t_param *param)
{
	ft_init_struc_ray(param);
	ft_init_struc_cast(param);
	ray_angle = normalize_angle(ray_angle);
	ft_ray_facing(param, ray_angle);
	ft_horz_vert_intersection(param, ray_angle);
	ft_clother_distance(param);
	if (param->cast.vert_hit_distance < param->cast.horz_hit_distance)
		param->rays.was_hitvertical = 1;
}
