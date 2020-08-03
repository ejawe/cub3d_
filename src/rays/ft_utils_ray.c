/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:18 by user42            #+#    #+#             */
/*   Updated: 2020/08/03 13:32:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	float distance;

	distance = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (distance);
}

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	ft_taille_image(t_param *param)
{
	param->tex[0].size_file = 0;
	param->tex[1].size_file = 0;
	param->tex[2].size_file = 0;
	param->tex[3].size_file = 0;
	param->tex[4].size_file = 0;
	while (param->tex[0].data_text[param->tex[0].size_file])
		param->tex[0].size_file++;
	while (param->tex[1].data_text[param->tex[1].size_file])
		param->tex[1].size_file++;
	while (param->tex[2].data_text[param->tex[2].size_file])
		param->tex[2].size_file++;
	while (param->tex[3].data_text[param->tex[3].size_file])
		param->tex[3].size_file++;
	while (param->tex[4].data_text[param->tex[4].size_file])
		param->tex[4].size_file++;
}
