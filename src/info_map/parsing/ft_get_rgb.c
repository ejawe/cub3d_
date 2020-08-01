/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:43 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:02:39 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_check_error_rgb(char *line, int i, int error)
{
	int coma;
	int nb;

	coma = 0;
	nb = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			nb++;
			while (ft_isdigit(line[i]))
				i++;
		}
		if (line[i] == ',')
			coma++;
		if (line[i] == '\0')
			break ;
		i++;
	}
	if (!(coma == 2 && nb == 3))
		error = 6;
	return (error);
}

int		ft_get_number_rgb(char *line, int i, t_param *param)
{
	int j;
	int v;

	j = 0;
	v = 0;
	while (line[i] && j < 3)
	{
		if (ft_isdigit(line[i]))
		{
			if (line[0] == 'F')
				param->infomap.f_rgb[j] = ft_get_number(&line[i]);
			else if (line[0] == 'C')
				param->infomap.c_rgb[j] = ft_get_number(&line[i]);
			j++;
			while (ft_isdigit(line[i]))
				i++;
			if (line[i] == '\0')
				i--;
			v = 0;
		}
		if (line[i] == ',')
			v++;
		i++;
	}
	return (i);
}

void	ft_color_hexa(char *line, t_param *param)
{
	if (line[0] == 'F')
	{
		param->infomap.f_color = (((param->infomap.f_rgb[0]) << 16) +
				((param->infomap.f_rgb[1]) << 8) +
				(param->infomap.f_rgb[2]));
	}
	if (line[0] == 'C')
	{
		param->infomap.c_color = (((param->infomap.c_rgb[0]) << 16) +
				((param->infomap.c_rgb[1]) << 8) +
				(param->infomap.c_rgb[2]));
	}
}

int		ft_get_rgb(char *line, t_param *param, int error)
{
	int i;

	i = 1;
	while (line[i] && line[i] == ' ')
		i++;
	error = ft_check_error_rgb(line, i, error);
	i = ft_get_number_rgb(line, i, param);
	ft_color_hexa(line, param);
	while (line[i])
	{
		if (line[i] != ' ')
			error = 6;
		i++;
	}
	return (error);
}
