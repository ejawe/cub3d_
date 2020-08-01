/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:36 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 13:56:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_check_error_resolution(char *line, int i, t_param *param, int error)
{
	while (line[i])
	{
		if (line[i] != ' ')
			error = 7;
		i++;
	}
	if (param->infomap.reso_x < 50)
		param->infomap.reso_x = 50;
	if (param->infomap.reso_y <= 50)
		param->infomap.reso_y = 50;
	return (error);
}

int		ft_get_resolution(char *line, t_param *param, int error)
{
	int i;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		param->infomap.reso_x = ft_get_number(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
	}
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		param->infomap.reso_y = ft_get_number(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
	}
	error = ft_check_error_resolution(line, i, param, error);
	return (error);
}
