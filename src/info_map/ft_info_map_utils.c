/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:01 by user42            #+#    #+#             */
/*   Updated: 2020/07/26 17:38:56 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int		ft_get_number(char *line)
{
	int		i;
	char	*stock;
	int		nb;

	i = 0;
	stock = NULL;
	nb = 0;
	while (ft_isdigit(line[i]))
		i++;
	stock = ft_substr(line, 0, i + 1);
	nb = ft_atoi(stock);
	free(stock);
	stock = NULL;
	return (nb);
}

int		ft_len_base(char *base)
{
	int lb;

	lb = 0;
	while (base[lb] != '\0')
		lb++;
	return (lb);
}
