/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejawe <ejawe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:05:04 by user42            #+#    #+#             */
/*   Updated: 2020/08/02 17:16:23 by ejawe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <unistd.h>
# include <math.h>
# include <X11/X.h>

# define FALSE 0
# define TRUE 1
# define N 30
# define S 35
# define E 21
# define W 39
# define KEY_ESC 65307
# define KEY_TR_LT 65361
# define KEY_UP 65362
# define KEY_TR_RT 65363
# define KEY_DN 65364
# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_ENTER 65293
# define TWO_PI 6.28318530
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_EXIT 17
# define MINIMAP_SCALE_FACTOR 0.5
# define FOV_ANGLE 1.0471975511965977f
# define NUM_TEX 5
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

typedef struct		s_infomap
{
	int				reso_x;
	int				reso_y;
	int				f_rgb[3];
	int				c_rgb[3];
	int				f_color;
	int				c_color;
	char			**tabmap;
	char			*string;
	int				nb_line_map;
	int				position_map;
	char			orientation;
	int				other;
}					t_infomap;

typedef struct		s_player
{
	float			x;
	float			y;
	float			newx;
	float			newy;
	float			width;
	float			height;
	int				turn_direction;
	int				walk_direction;
	float			rotation_angle;
	float			walk_speed;
	float			turn_speed;
	float			planex;
	float			planey;
	float			dirx;
	float			diry;
	int				side;
}					t_player;

typedef struct		s_map
{
	int				lx;
	int				ly;
	unsigned int	window_width;
	unsigned int	window_height;
	int				num_rays;
	int				wall_strip_width;
	int				num_cols;
	int				tile_size;
}					t_map;

typedef struct		s_cast_ray
{
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	int				found_horzwallhit;
	float			horz_wallhitx;
	float			horz_wallhity;
	float			next_horztouchx;
	float			next_horztouchy;
	int				found_vertwallhit;
	float			vert_wallhitx;
	float			vert_wallhity;
	float			next_verttouchx;
	float			next_verttouchy;
	float			horz_hit_distance;
	float			vert_hit_distance;
	float			*buffer;
}					t_cast;

typedef struct		s_cast_allrays
{
	float			wall_st_height;
	float			dis_projection_plane;
	float			correct_wall_dis;
	int				color;
	int				wall_top_pixel;
	int				wall_bottom_pixel;
	int				texture_offsetx;
	int				texture_offsety;
	int				dis_from_top;
}					t_cast_all;

typedef struct		s_rays
{
	float			ray_angle;
	float			wall_hitx;
	float			wall_hity;
	float			distance;
	int				was_hitvertical;
	int				is_rayfacing_up;
	int				is_rayfacing_down;
	int				is_rayfacing_left;
	int				is_rayfacing_right;
}					t_rays;

typedef struct		s_sprite
{
	float			x;
	float			y;
	int				num_sprites;
	float			**sprite;
	float			*sprite_dis;
	float			spritex;
	float			spritey;
	float			sprite_stripheight;
	int				startx;
	int				endx;
	int				starty;
	int				endy;
	int				s_width;
	int				s_height;
	int				s_screenx;
	float			transformx;
	float			transformy;
}					t_sprite;

typedef	struct		s_texture
{
	void			*img_file;
	int				*data_text;
	int				img_width;
	int				img_height;
	char			*path_file;
	int				size_file;
}					t_texture[NUM_TEX];

typedef	struct		s_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				argument;
	int				check_double[8];
	t_rays			rays;
	t_map			map;
	t_player		player;
	t_cast			cast;
	t_cast_all		cast_all;
	t_infomap		infomap;
	t_sprite		sprite;
	t_texture		tex;
}					t_param;

typedef	struct		s_file_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}					t_file_header;

typedef struct		s_info_header
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	planes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	total_color;
	unsigned int	important_color;
}					t_info_header;

void				ft_init_struct_map(t_param *param);
void				ft_get_info(int fd, t_param *param);
int					ft_parse_line(char *line, t_param *param, int error);
int					ft_get_rgb(char *line, t_param *param, int error);
int					ft_get_path_texture(char *line, t_param *param, int error);
int					ft_get_resolution(char *line, t_param *param, int error);
int					ft_create_tab_map(t_param *param);
void				ft_free_tab_map(t_param *param);
int					ft_check_wall_surrounded(t_param *param, int error);
int					ft_check_wall_condition(t_param *param,
						char **newstr, int error);
int					ft_check_correct_map(t_param *param, int error);
int					ft_space(char **newstr, int i, int j, char c);
int					ft_get_orientation(t_param *param, int error);
void				ft_info_screen_map(t_param *param);
int					ft_get_number(char *line);
char				*ft_get_string(char *line, t_param *param);
int					ft_check_extention(char *arg, int fd);
int					ft_init_game(t_param *param);
int					key_press(int key, void *data);
int					key_release(int key, void *data);
void				ft_init_struc_ray(t_param *param);
void				ft_init_struc_cast(t_param *param);
float				distance_between_points(float x1, float y1,
						float x2, float y2);
float				normalize_angle(float angle);
int					ft_init_texture(t_param *param);
void				ft_init_struct_sprite(t_param *param);
void				ft_cast_ray(float ray_angle, t_param *param);
void				ft_horz_vert_intersection(t_param *param, float ray_angle);
void				ft_cast_all_rays(t_param *param);
void				ft_init_player(t_param *param);
void				ft_orientation(t_param *param);
void				ft_move_player(t_param *param);
int					map_has_wall_at(float x, float y, t_param *param);
void				ft_draw_floor_ceiling(t_param *param);
void				ft_init_sprite(t_param *param);
void				ft_sprite(t_param *param);
void				ft_sort_sprite(t_param *param);
void				ft_free_sprite(t_param *param);
void				ft_deal_sprite(t_param *param, int number);
int					ft_sprite_visible(t_param *param, int n);
void				ft_draw_sprite(t_param *param);
int					ft_color_texture_sprite(t_param *param, int x, int y);
void				ft_free_all(t_param *param, int code_error);
void				ft_my_putnbr_base(long long nbr, char *base);
void				ft_save(t_param *param, char *name);
void				ft_check_save_name(t_param *param, char *av, int fd);
void				ft_writecolor(int fd, t_param *param,
						unsigned int img_size);
int					exit_loop(void *data);
void				ft_code_error(int code_error);
void				ft_render_map(t_param *param);
void				ft_render_player(t_param *param);
void				ft_taille_image(t_param *param);
#endif
