/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:30 by user42            #+#    #+#             */
/*   Updated: 2020/08/03 13:30:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int		ft_check_error_path_texture(char *line, int i,
									t_param *param, int error)
{
	while (line[i] && line[i] == ' ')
	{
		if (line[i] != ' ')
			error = 5;
		i++;
	}
	return (error);
}

int		ft_check_extention_xpm(char *str)
{
	int i;

	i = 2;
	while (str[i] != '\0')
	{
		if ((str[i] == '.' && str[i + 1] != 'x' &&
				str[i + 2] != 'p' && str[i + 3] != 'm') ||
				(str[i] == '.' && ft_strlen(&str[i]) != 4))
		{
			ft_putstr("Error\nCheck extention xpm.\n");
			exit(0);
		}
		i++;
	}
	return (0);
}

void	ft_check_after(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ')
		{
			ft_putstr("Error\nCheck extention xpm.\n");
			exit(0);
		}
		i++;
	}
}

char	*ft_get_string(char *line, t_param *param)
{
	int		i;
	int		s;
	char	*stock;

	i = 0;
	s = 0;
	stock = NULL;
	while (line[s] == ' ')
		s++;
	i = s;
	if (line[i] == '.' && line[i + 1] == '/')
	{
		i = s + 2;
		while (line[i] && (ft_isalpha(line[i]) || line[i] == '_' ||
					line[i] == '-' || line[i] == '/' || line[i] == '.' ||
					ft_isdigit(line[i])))
			i++;
		stock = ft_substr(line, s, i - s);
		ft_check_after(line, i);
		ft_check_extention_xpm(stock);
	}
	else
		ft_free_all(param, 5);
	return (stock);
}

int		ft_get_path_texture(char *line, t_param *param, int error)
{
	int i;

	i = 0;
	if (line[0] == 'N' && line[1] == 'O' &&
	param->tex[0].path_file == NULL)
		param->tex[0].path_file = ft_get_string(&line[2], param);
	else if (line[0] == 'S' && line[1] == 'O' &&
	param->tex[1].path_file == NULL)
		param->tex[1].path_file = ft_get_string(&line[2], param);
	else if (line[0] == 'W' && line[1] == 'E' &&
	param->tex[3].path_file == NULL)
		param->tex[3].path_file = ft_get_string(&line[2], param);
	else if (line[0] == 'E' && line[1] == 'A' &&
	param->tex[2].path_file == NULL)
		param->tex[2].path_file = ft_get_string(&line[2], param);
	else if (line[0] == 'S' && line[1] == ' ' &&
	param->tex[4].path_file == NULL)
		param->tex[4].path_file = ft_get_string(&line[2], param);
	else
		error = 5;
	error = ft_check_error_path_texture(line, i, param, error);
	return (error);
}
