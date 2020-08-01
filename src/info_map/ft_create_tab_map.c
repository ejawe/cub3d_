/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:02:15 by user42            #+#    #+#             */
/*   Updated: 2020/07/28 12:18:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_put_one(t_param *param, int j, int tab_nb)
{
	if (j < param->map.num_cols)
	{
		while (j < param->map.num_cols)
		{
			param->infomap.tabmap[tab_nb][j] = '1';
			j++;
		}
	}
	return (j);
}

void	ft_tab_map_content(t_param *param)
{
	int i;
	int tab_nb;
	int j;

	i = 0;
	tab_nb = 0;
	j = 0;
	while (tab_nb < param->infomap.nb_line_map)
	{
		j = 0;
		while (param->infomap.string[i] != '.')
		{
			if (param->infomap.string[i] == ' ')
				param->infomap.tabmap[tab_nb][j] = '1';
			else
				param->infomap.tabmap[tab_nb][j] = param->infomap.string[i];
			j++;
			i++;
		}
		j = ft_put_one(param, j, tab_nb);
		param->infomap.tabmap[tab_nb][j] = '\0';
		i++;
		tab_nb++;
	}
}

void	ft_init_tab_map(t_param *param)
{
	int tab_nb;
	int j;

	tab_nb = 0;
	j = 0;
	while (tab_nb < param->infomap.nb_line_map)
	{
		j = 0;
		while (j < param->map.num_cols)
		{
			param->infomap.tabmap[tab_nb][j] = '\0';
			j++;
		}
		param->infomap.tabmap[tab_nb][j] = '\0';
		tab_nb++;
	}
}

int		ft_create_tab_map(t_param *param)
{
	int i;

	i = 0;
	ft_info_screen_map(param);
	if (!(param->infomap.tabmap = (char **)malloc(sizeof(char *) *
					(param->infomap.nb_line_map + 1))))
		return (0);
	while (i < param->infomap.nb_line_map)
	{
		if (!(param->infomap.tabmap[i] = (char *)malloc(sizeof(char) *
				(param->map.num_cols + 1))))
			return (0);
		i++;
	}
	param->infomap.tabmap[i] = NULL;
	ft_init_tab_map(param);
	ft_tab_map_content(param);
	return (0);
}
