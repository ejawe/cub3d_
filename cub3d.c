/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:46:01 by user42            #+#    #+#             */
/*   Updated: 2020/08/01 14:17:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int		ft_game_loop(t_param *param)
{
	if (!(param->img_ptr = mlx_new_image(param->mlx_ptr,
		param->map.window_width, param->map.window_height)))
	{
		ft_putstr_fd("failed to create image", 1);
		exit(0);
	}
	if (!(param->data = (int *)mlx_get_data_addr(param->img_ptr,
		&param->bpp, &param->size_line, &param->endian)))
	{
		ft_putstr_fd("failed to get_data img", 1);
		exit(0);
	}
	ft_draw_floor_ceiling(param);
	ft_move_player(param);
	ft_cast_all_rays(param);
	ft_sprite(param);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (param->argument == 3)
		ft_save(param, "save.bmp");
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
		param->img_ptr, 0, 0);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_param param;
	int		fd;

	fd = 0;
	param.argument = ac;
	if (ac == 2 || ac == 3)
	{
		fd = ft_check_extention(av[1], fd);
		if (ac == 3)
			ft_check_save_name(&param, av[2], fd);
		ft_init_struct_map(&param);
		ft_get_info(fd, &param);
		close(fd);
		ft_init_game(&param);
		mlx_hook(param.win_ptr, KeyPress, KeyPressMask,
				&key_press, &param);
		mlx_hook(param.win_ptr, KeyRelease, KeyReleaseMask,
				&key_release, &param);
		mlx_hook(param.win_ptr, 17, 1L << 17, exit_loop, &param);
		mlx_loop_hook(param.mlx_ptr, &ft_game_loop, &param);
		mlx_loop(param.mlx_ptr);
	}
	else
		ft_putstr_fd("Error\nCheck argument number.\n", 1);
	return (0);
}
