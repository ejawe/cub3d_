/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struc_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:14 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 22:15:11 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_init_struc_cast(t_param *param)
{
	param->cast.xintercept = 0;
	param->cast.yintercept = 0;
	param->cast.xstep = 0;
	param->cast.ystep = 0;
	param->cast.found_horzwallhit = 0;
	param->cast.horz_wallhitx = 0;
	param->cast.horz_wallhity = 0;
	param->cast.next_horztouchx = 0;
	param->cast.next_horztouchy = 0;
	param->cast.found_vertwallhit = 0;
	param->cast.vert_wallhitx = 0;
	param->cast.vert_wallhity = 0;
	param->cast.next_verttouchx = 0;
	param->cast.next_verttouchy = 0;
	param->cast.horz_hit_distance = 0;
	param->cast.vert_hit_distance = 0;
}

void	ft_init_struc_ray(t_param *param)
{
	param->rays.ray_angle = 0;
	param->rays.wall_hitx = 0;
	param->rays.wall_hity = 0;
	param->rays.distance = 0;
	param->rays.was_hitvertical = 0;
	param->rays.is_rayfacing_up = 0;
	param->rays.is_rayfacing_down = 0;
	param->rays.is_rayfacing_left = 0;
	param->rays.is_rayfacing_right = 0;
}
