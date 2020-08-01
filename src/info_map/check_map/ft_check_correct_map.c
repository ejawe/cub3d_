/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_correct_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:04:37 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:03:41 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_check_points(t_param *param, int error)
{
	int i;
	int points;

	i = 0;
	points = 0;
	while (param->infomap.string[i])
	{
		if (param->infomap.string[i] == '.')
			points++;
		i++;
	}
	if (points > param->infomap.nb_line_map)
		error = 9;
	return (error);
}

int		ft_check_orientation(t_param *param, int error)
{
	if (ft_strchr(param->infomap.string, 'N') == NULL &&
			ft_strchr(param->infomap.string, 'S') == NULL &&
			ft_strchr(param->infomap.string, 'E') == NULL &&
			ft_strchr(param->infomap.string, 'W') == NULL)
		error = 11;
	return (error);
}

int		ft_4_characters(t_param *param, int error)
{
	int i;

	i = 0;
	while (param->infomap.string[i])
	{
		if (param->infomap.string[i] != '1' &&
		param->infomap.string[i] != '0' && param->infomap.string[i] != '2' &&
		param->infomap.string[i] != 'N' && param->infomap.string[i] != 'S' &&
		param->infomap.string[i] != 'E' && param->infomap.string[i] != 'W' &&
		param->infomap.string[i] != '.' && param->infomap.string[i] != ' ')
			error = 9;
		i++;
	}
	if (ft_strchr(param->infomap.string, '2') == NULL ||
			ft_strchr(param->infomap.string, '1') == NULL ||
			ft_strchr(param->infomap.string, '0') == NULL)
		error = 10;
	return (error);
}

int		ft_check_correct_map(t_param *param, int error)
{
	error = ft_4_characters(param, error);
	error = ft_check_points(param, error);
	error = ft_check_orientation(param, error);
	error = ft_get_orientation(param, error);
	error = ft_check_wall_surrounded(param, error);
	return (error);
}
