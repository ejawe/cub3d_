/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:45 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 17:00:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_tab_map(t_param *param)
{
	int i;

	i = 0;
	while (i < param->infomap.nb_line_map)
	{
		free(param->infomap.tabmap[i]);
		i++;
	}
	free(param->infomap.tabmap);
}

void	ft_free_sprite(t_param *param)
{
	int i;

	i = 0;
	if (param->sprite.sprite != 0)
	{
		while (i < param->sprite.num_sprites)
		{
			free(param->sprite.sprite[i]);
			i++;
		}
		free(param->sprite.sprite);
	}
	if (param->sprite.sprite_dis != 0)
		free(param->sprite.sprite_dis);
	if (param->cast.buffer != 0)
		free(param->cast.buffer);
}

void	ft_code_error(int code_error)
{
	if (code_error == 1 || code_error == 0)
		ft_putstr_fd("End of the game !\n", 1);
	else if (code_error == 2 || code_error == 12)
		ft_putstr_fd("Error\nmap\n", 1);
	else if (code_error == 3)
		ft_putstr_fd("Error\nyou put parameter twice\n", 1);
	else if (code_error == 4)
		ft_putstr_fd("Error\nOne parameter is missing.\n", 1);
	else if (code_error == 5)
		ft_putstr_fd("Error\npath texture.\n", 1);
	else if (code_error == 6)
		ft_putstr_fd("Error\nfloor or ceiling parameter\n", 1);
	else if (code_error == 7 || code_error == 8)
		ft_putstr_fd("Error\non resolution.\n", 1);
	else if (code_error == 9 || code_error == 10 || code_error == 11)
		ft_putstr_fd("Error\nformat map on character or orientation.\n", 1);
	else if (code_error == 13)
		ft_putstr_fd("Error\nmap not surrounded by wall.\n", 1);
	else if (code_error == 14)
		ft_putstr_fd("Error\nFailed to create image.\n", 1);
	else if (code_error == 15)
		ft_putstr_fd("Error\nmalloc.\n", 1);
	else if (code_error == 16)
		ft_putstr_fd("Error\nfailed to init mlx or create window.\n", 1);
}

void	ft_free_all(t_param *param, int code_error)
{
	int i;

	i = 0;
	if (param->mlx_ptr)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		while (i < NUM_TEX)
		{
			if (param->tex[i].img_file)
				mlx_destroy_image(param->mlx_ptr, param->tex[i].img_file);
			i++;
		}
	}
	ft_free_sprite(param);
	i = -1;
	while (++i < NUM_TEX)
	{
		if (param->tex[i].path_file != NULL)
			free(param->tex[i].path_file);
	}
	if (param->infomap.tabmap != NULL)
		ft_free_tab_map(param);
	if (code_error != 0)
		ft_code_error(code_error);
	exit(0);
}
