/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha_or_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:24 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:02:02 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_error_double(int check_double[], int error)
{
	int j;

	j = 0;
	while (j < 8)
	{
		if (check_double[j] == 2)
			error = 3;
		j++;
	}
	return (error);
}

int		ft_check_double(char *line, int i, int check_double[], int error)
{
	if (line[i] == 'R')
		check_double[0] += 1;
	else if (line[i] == 'N')
		check_double[1] += 1;
	else if (line[i] == 'S' && line[i + 1] == 'O')
		check_double[2] += 1;
	else if (line[i] == 'S' && line[i + 1] == ' ')
		check_double[3] += 1;
	else if (line[i] == 'W')
		check_double[4] += 1;
	else if (line[i] == 'E')
		check_double[5] += 1;
	else if (line[i] == 'F')
		check_double[6] += 1;
	else if (line[i] == 'C')
		check_double[7] += 1;
	error = ft_error_double(check_double, error);
	return (error);
}

int		ft_get_info_alpha(char *line, int i, t_param *param, int error)
{
	error = 0;
	if (line[i] == 'R')
		error = ft_get_resolution(&line[i], param, error);
	else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E')
		error = ft_get_path_texture(&line[i], param, error);
	else if (line[i] == 'F' || line[i] == 'C')
		error = ft_get_rgb(&line[i], param, error);
	else
		error = 2;
	if (param->infomap.position_map == 1)
		error = 2;
	error = ft_check_double(line, i, param->check_double, error);
	return (error);
}

int		ft_get_info_digit(char *line, int i, t_param *param, int error)
{
	char	*temp;
	char	*end_line;

	temp = NULL;
	end_line = NULL;
	end_line = ft_strnew(0);
	temp = end_line;
	end_line = ft_strjoin(line, ".");
	free(temp);
	if (param->infomap.other == 1)
		error = 12;
	temp = param->infomap.string;
	param->infomap.string = ft_strjoin(param->infomap.string, end_line);
	free(temp);
	free(end_line);
	param->infomap.nb_line_map++;
	param->infomap.position_map = 1;
	return (error);
}

int		ft_parse_line(char *line, t_param *param, int error)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isalpha(line[i]))
		error = ft_get_info_alpha(line, i, param, error);
	else if (ft_isdigit(line[i]))
		error = ft_get_info_digit(line, i, param, error);
	if (ft_isalpha(line[i]) == 0 && ft_isdigit(line[i]) == 0 &&
	param->infomap.position_map == 1)
		param->infomap.other = 1;
	return (error);
}
