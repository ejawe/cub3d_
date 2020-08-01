/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_all_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:06:22 by user42            #+#    #+#             */
/*   Updated: 2020/08/01 18:40:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_init_struc_cast_all_rays(t_param *param)
{
	param->cast_all.color = 0xffffff;
	param->cast_all.dis_projection_plane = 0;
	param->cast_all.correct_wall_dis = 0;
	param->cast_all.wall_st_height = 0;
	param->cast_all.wall_top_pixel = 0;
	param->cast_all.wall_bottom_pixel = 0;
	param->cast_all.texture_offsetx = 0;
	param->cast_all.texture_offsety = 0;
	param->cast_all.dis_from_top = 0;
}

void	ft_ray_top_bottom(t_param *param, float ray_angle)
{
	param->cast_all.correct_wall_dis = param->rays.distance *
		cos(ray_angle - param->player.rotation_angle);
	param->cast_all.dis_projection_plane = (param->map.window_width / 2) /
		tan(FOV_ANGLE / 2);
	param->cast_all.wall_st_height = (param->map.tile_size /
			param->cast_all.correct_wall_dis) *
		param->cast_all.dis_projection_plane;
	param->cast_all.wall_top_pixel = (param->map.window_height / 2) -
		(param->cast_all.wall_st_height / 2);
	param->cast_all.wall_top_pixel = param->cast_all.wall_top_pixel < 0 ? 0
		: param->cast_all.wall_top_pixel;
	param->cast_all.wall_bottom_pixel = (param->map.window_height / 2) +
		(param->cast_all.wall_st_height / 2);
	param->cast_all.wall_bottom_pixel = param->cast_all.wall_bottom_pixel >
		param->map.window_height ?
		param->map.window_height : param->cast_all.wall_bottom_pixel;
}

void	ft_color_tex(t_param *param, float wall_hit, int num)
{
	//printf("i = %d  -  taille = %d\n", num, param->tex[num].size_file);
	long int a = sizeof(param->tex[num].data_text);
	//printf("a = %d \n", num, param->tex[num].size_file);
	param->cast_all.texture_offsetx = (int)
			((wall_hit * param->tex[num].img_width)
			/ param->map.tile_size) % param->tex[num].img_width;
	param->cast_all.texture_offsety = param->cast_all.dis_from_top *
		((float)param->tex[num].img_height / param->cast_all.wall_st_height);
	//printf("size = %d\n",(param->tex[num].img_width * param->cast_all.texture_offsety) + param->cast_all.texture_offsetx);
	//printf("--------  window_width = %d  -  window_height = %d\n", param->map.window_width, param->map.window_height);

	if (((param->tex[num].img_width * param->cast_all.texture_offsety) +
			param->cast_all.texture_offsetx) < a)
		return ;
	param->cast_all.color =
		param->tex[num].data_text[(param->tex[num].img_width *
		param->cast_all.texture_offsety) +
		param->cast_all.texture_offsetx];
}

void	ft_walls_conditions(t_param *param)
{
	if (param->rays.was_hitvertical && param->rays.is_rayfacing_right)
		ft_color_tex(param, param->cast.vert_wallhity, EAST);
	else if (param->rays.was_hitvertical && param->rays.is_rayfacing_left)
		ft_color_tex(param, param->cast.vert_wallhity, WEST);
	else if (param->rays.was_hitvertical == 0 && param->rays.is_rayfacing_up)
		ft_color_tex(param, param->cast.horz_wallhitx, NORTH);
	else if (param->rays.was_hitvertical == 0 && param->rays.is_rayfacing_down)
		ft_color_tex(param, param->cast.horz_wallhitx, SOUTH);
}

void	ft_cast_all_rays(t_param *param)
{
	int		strip_id;
	int		y;
	float	ray_angle;

	strip_id = 0;
	ft_init_struc_cast_all_rays(param);
	ray_angle = normalize_angle(param->player.rotation_angle - (FOV_ANGLE / 2));
	ft_taille_image(param);
	while (strip_id < param->map.num_rays)
	{
		ft_cast_ray(ray_angle, param);
		ft_ray_top_bottom(param, ray_angle);
		param->cast.buffer[strip_id] = param->cast_all.correct_wall_dis;
		y = param->cast_all.wall_top_pixel - 1;
		while (y++ < param->cast_all.wall_bottom_pixel)
		{
			param->cast_all.dis_from_top = y + (param->cast_all.wall_st_height
			/ 2) - (param->map.window_height / 2);
			ft_walls_conditions(param);
			//param->cast_all.color = 0xFFFFFF;
			param->data[(param->map.window_width * y) + strip_id] =
				param->cast_all.color;
		}
		ray_angle += (FOV_ANGLE / param->map.num_rays);
		strip_id++;
	}
}
