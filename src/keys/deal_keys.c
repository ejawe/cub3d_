/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:36 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 18:31:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		exit_loop(void *data)
{
	t_param *param;

	param = (t_param *)data;
	ft_free_all(param, 1);
	return (0);
}

int		key_press(int key, void *data)
{
	t_param *param;

	param = (t_param *)data;
	if (key == KEY_W)
		param->player.walk_direction = +1;
	else if (key == KEY_S)
		param->player.walk_direction = -1;
	else if (key == KEY_A)
		param->player.walk_direction = -1;
	else if (key == KEY_D)
		param->player.walk_direction = +1;
	else if (key == KEY_TR_RT)
		param->player.turn_direction = +1;
	else if (key == KEY_TR_LT)
		param->player.turn_direction = -1;
	else if (key == KEY_ESC)
		ft_free_all(param, 1);
	if (key == KEY_W || key == KEY_S)
		param->player.side = 0;
	if (key == KEY_A || key == KEY_D)
		param->player.side = 1;
	return (0);
}

int		key_release(int key, void *data)
{
	t_param *param;

	param = (t_param *)data;
	if (key == KEY_W)
		param->player.walk_direction = 0;
	else if (key == KEY_S)
		param->player.walk_direction = 0;
	else if (key == KEY_A)
		param->player.walk_direction = 0;
	else if (key == KEY_D)
		param->player.walk_direction = 0;
	else if (key == KEY_TR_RT)
		param->player.turn_direction = 0;
	else if (key == KEY_TR_LT)
		param->player.turn_direction = 0;
	if (key == KEY_W || key == KEY_S ||
		key == KEY_A || key == KEY_D)
		param->player.side = 0;
	return (0);
}
