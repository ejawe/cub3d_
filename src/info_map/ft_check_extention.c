/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:54:16 by user42            #+#    #+#             */
/*   Updated: 2020/08/03 18:02:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_extention(char *arg, int fd)
{
	int i;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1 || ft_strchr(arg, '.') == 0)
	{
		ft_putstr_fd("Error\nCheck file name.\n", 1);
		close(fd);
		exit(0);
	}
	while (arg[i] != '\0')
	{
		if (arg[0] == '.' && arg[0 + 1] == '/')
			i = i + 2;
		if ((arg[0] == '.' && arg[0 + 1] == '/' && arg[0 + 2] == '\0') ||
			(arg[i] == '.' && arg[i + 1] != 'c' &&
			arg[i + 2] != 'u' && arg[i + 3] != 'b') ||
			(arg[i] == '.' && ft_strlen(&arg[i]) != 4))
		{
			ft_putstr_fd("Error\nCheck extention cub.\n", 1);
			close(fd);
			exit(0);
		}
		i++;
	}
	return (fd);
}
