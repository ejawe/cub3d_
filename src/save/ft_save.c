/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:07:32 by user42            #+#    #+#             */
/*   Updated: 2020/07/27 18:19:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_fillheader(t_file_header *file_header,
			t_info_header *info_header, t_param *param)
{
	file_header->type[0] = 0x42;
	file_header->type[1] = 0x4D;
	file_header->size =
		(param->map.window_height * param->map.window_width * 4) + 54;
	file_header->reserved = 0x00000000;
	file_header->offset = 0x36;
	info_header->size = 40;
	info_header->width = param->map.window_width;
	info_header->height = -param->map.window_height;
	info_header->planes = 1;
	info_header->bpp = 32;
	info_header->compression = 0;
	info_header->img_size =
		(param->map.window_width * param->map.window_height * 4);
	info_header->x_ppm = 2835;
	info_header->y_ppm = 2835;
	info_header->total_color = 0;
	info_header->important_color = 0;
}

void	ft_writebmp(t_file_header *file_header,
			t_info_header *info_header, int fd)
{
	write(fd, &file_header->type, 2);
	write(fd, &file_header->size, 4);
	write(fd, &file_header->reserved, 4);
	write(fd, &file_header->offset, 4);
	write(fd, &info_header->size, 4);
	write(fd, &info_header->width, 4);
	write(fd, &info_header->height, 4);
	write(fd, &info_header->planes, 2);
	write(fd, &info_header->bpp, 2);
	write(fd, &info_header->compression, 4);
	write(fd, &info_header->img_size, 4);
	write(fd, &info_header->x_ppm, 4);
	write(fd, &info_header->y_ppm, 4);
	write(fd, &info_header->total_color, 4);
	write(fd, &info_header->important_color, 4);
}

void	ft_writecolor(int fd, t_param *param, unsigned int img_size)
{
	char	*pixel_array;
	int		image_size;
	int		i;
	int		j;

	if (!(pixel_array = malloc(sizeof(char) * img_size)))
	{
		ft_putstr_fd("Error\nmalloc", 1);
		return ;
	}
	i = 0;
	j = 0;
	img_size = img_size / 4;
	while (i < img_size)
	{
		pixel_array[j++] = param->data[i] & 255;
		pixel_array[j++] = (param->data[i] & 255 << 8) >> 8;
		pixel_array[j++] = (param->data[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	write(fd, pixel_array, img_size *= 4);
	free(pixel_array);
}

void	ft_save(t_param *param, char *name)
{
	int				fd;
	t_file_header	file_header;
	t_info_header	info_header;

	if (!((fd = open(name, O_WRONLY | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		ft_putstr_fd("Error\nOn open file bmp", 1);
		return ;
	}
	ft_fillheader(&file_header, &info_header, param);
	ft_writebmp(&file_header, &info_header, fd);
	ft_writecolor(fd, param, info_header.img_size);
	close(fd);
	ft_free_all(param, 0);
}
