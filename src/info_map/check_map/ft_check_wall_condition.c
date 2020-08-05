/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall_condition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:04:46 by user42            #+#    #+#             */
/*   Updated: 2020/08/05 16:53:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_check_wall(t_param *param, char **newstr, char c, int error)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (i < param->infomap.nb_line_map)
	{
		j = 0;
		while (newstr[i][j] != '\0')
		{
			if ((i == 0 && newstr[i][j] == c) ||
			(j == 0 && newstr[i][j] == c) ||
			((i == param->infomap.nb_line_map - 1 ||
			j == (ft_strlen(newstr[i]) - 1)) && newstr[i][j] == c))
			{
				return (13);
			}
			if (ft_space(newstr, i, j, c) == 1)
				error = 13;
			j++;
		}
		i++;
	}
	return (error);
}

int		ft_check_wall_condition(t_param *param, char **newstr, int error)
{
	error = ft_check_wall(param, newstr, '0', error);
	error = ft_check_wall(param, newstr, '2', error);
	error = ft_check_wall(param, newstr, 'N', error);
	error = ft_check_wall(param, newstr, 'S', error);
	error = ft_check_wall(param, newstr, 'E', error);
	error = ft_check_wall(param, newstr, 'W', error);
	return (error);
}
