/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_save_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:24 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 18:18:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_check_save_name(t_param *param, char *av, int fd)
{
	char *str;

	str = ft_substr("--save", 0, 6);
	if (ft_strcmp((const char*)av, (const char*)str) != 0)
	{
		ft_putstr_fd("Error\nCheck name argument save image.\n", 1);
		close(fd);
		exit(0);
	}
	free(str);
}
