/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall_surrounded.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:04:46 by user42            #+#    #+#             */
/*   Updated: 2020/07/28 12:15:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

char	**ft_wall_surrounded_content(t_param *param, char **newstr, int i,
		int j)
{
	int tab;

	tab = 0;
	while (tab < param->infomap.nb_line_map)
	{
		j = 0;
		while (param->infomap.string[i] != '.')
		{
			newstr[tab][j] = param->infomap.string[i];
			j++;
			i++;
		}
		if (j < param->map.num_cols)
		{
			while (j < param->map.num_cols)
			{
				newstr[tab][j] = ' ';
				j++;
			}
		}
		newstr[tab][j] = '\0';
		i++;
		tab++;
	}
	return (newstr);
}

void	free_newstr(t_param *param, char **newstr)
{
	int i;

	i = 0;
	while (i < param->infomap.nb_line_map)
	{
		free(newstr[i]);
		i++;
	}
	free(newstr);
}

int		ft_nb_col(t_param *param)
{
	int	i;
	int len;
	int avant;

	i = 0;
	len = 0;
	avant = 0;
	while (param->infomap.string[i])
	{
		len = 0;
		while (param->infomap.string[i] != '.')
		{
			len++;
			i++;
		}
		if (len > avant)
			avant = len;
		i++;
	}
	return (avant);
}

char	**ft_malloc_new_tab(t_param *param, char **newstr, int error)
{
	int i;

	i = 0;
	if (!(newstr = (char **)malloc(sizeof(char *) *
	(param->infomap.nb_line_map))))
		return (0);
	param->map.num_cols = ft_nb_col(param);
	while (i < param->infomap.nb_line_map)
	{
		if (!(newstr[i] = malloc(sizeof(char) * (param->map.num_cols + 1))))
			return (0);
		i++;
	}
	return (newstr);
}

int		ft_check_wall_surrounded(t_param *param, int error)
{
	char	**newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = ft_malloc_new_tab(param, newstr, error);
	newstr = ft_wall_surrounded_content(param, newstr, i, j);
	error = ft_check_wall_condition(param, newstr, error);
	free_newstr(param, newstr);
	return (error);
}
