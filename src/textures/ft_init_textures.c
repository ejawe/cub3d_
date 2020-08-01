/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:08:11 by user42            #+#    #+#             */
/*   Updated: 2020/08/01 14:07:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_init_texture(t_param *param)
{
	int	bpp;
	int	endian;
	int	size_line;
	int i;

	endian = 0;
	i = 0;
	while (i < NUM_TEX)
	{
		param->tex[i].img_file = NULL;
		param->tex[i].data_text = 0;
		if (param->tex[i].img_file = mlx_xpm_file_to_image(
					param->mlx_ptr, param->tex[i].path_file,
					&(param->tex[i].img_width), &(param->tex[i].img_height)))
			param->tex[i].data_text = (int *)mlx_get_data_addr(
					param->tex[i].img_file, &bpp, &size_line, &endian);
		else
			ft_free_all(param, 14);
		i++;
	}
	
	return (0);
}
