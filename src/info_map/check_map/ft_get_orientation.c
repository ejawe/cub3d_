/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_orientation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:04:52 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 20:04:55 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_get_orientation(t_param *param, int error)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (param->infomap.string[i])
	{
		if (param->infomap.string[i] > 'A' && param->infomap.string[i] < 'Z')
		{
			param->infomap.orientation = param->infomap.string[i];
			j++;
		}
		i++;
	}
	if (j > 1)
		error = 11;
	return (error);
}
