/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orientation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:06:15 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:34:38 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_deal_north(t_param *param)
{
	param->player.rotation_angle = 1.5 * M_PI;
	param->player.planex = -0.60;
	param->player.planey = 0.0;
	param->player.dirx = 0.0;
	param->player.diry = -1.0;
}

void	ft_deal_south(t_param *param)
{
	param->player.rotation_angle = M_PI / 2;
	param->player.planex = 0.60;
	param->player.planey = 0.0;
	param->player.dirx = 0.0;
	param->player.diry = 1.0;
}

void	ft_deal_east(t_param *param)
{
	param->player.rotation_angle = 2 * M_PI;
	param->player.planex = 0.0;
	param->player.planey = -0.60;
	param->player.dirx = 1.0;
	param->player.diry = 0.0;
}

void	ft_deal_west(t_param *param)
{
	param->player.rotation_angle = M_PI;
	param->player.planex = 0.0;
	param->player.planey = 0.60;
	param->player.dirx = -1.0;
	param->player.diry = 0.0;
}

void	ft_orientation(t_param *param)
{
	if (param->infomap.orientation == 'N')
		ft_deal_north(param);
	else if (param->infomap.orientation == 'S')
		ft_deal_south(param);
	else if (param->infomap.orientation == 'E')
		ft_deal_east(param);
	else if (param->infomap.orientation == 'W')
		ft_deal_west(param);
}
