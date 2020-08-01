MLX = -L./minilibx-linux/ ./minilibx-linux/libmlx.a -lm -lmlx -lX11 -lXext -lbsd

NAME = Cub3D

SRCS = 	cub3d.c \
		src/info_map/ft_init_struct_map.c \
		src/info_map/ft_get_info.c \
		src/info_map/ft_create_tab_map.c \
		src/info_map/ft_info_map_utils.c \
		src/info_map/ft_info_screen_map.c \
		src/info_map/ft_check_extention.c \
		src/info_map/parsing/ft_alpha_or_digit.c \
		src/info_map/parsing/ft_get_rgb.c \
		src/info_map/parsing/ft_get_path_texture.c \
		src/info_map/parsing/ft_get_resolution.c \
		src/info_map/check_map/ft_check_correct_map.c \
		src/info_map/check_map/ft_check_wall_surrounded.c \
		src/info_map/check_map/ft_check_wall_condition.c \
		src/info_map/check_map/ft_get_orientation.c \
		src/info_map/check_map/ft_utils_check_map.c \
		src/game/ft_init_game.c \
		src/keys/deal_keys.c \
		src/keys/free.c \
		src/save/ft_save.c \
		src/save/ft_check_save_name.c \
		src/rays/ft_init_struc_ray.c \
		src/rays/ft_utils_ray.c \
		src/rays/ft_cast_ray.c \
		src/rays/ft_horz_vert_intersection.c \
		src/rays/ft_cast_all_rays.c \
		src/textures/ft_init_textures.c \
		src/sprites/ft_init_sprite.c \
		src/sprites/ft_sprite.c \
		src/sprites/ft_sort_sprite.c \
		src/sprites/ft_deal_sprite.c \
		src/player/ft_deal_player.c \
		src/player/ft_init_player.c \
		src/player/ft_orientation.c \
		src/map/ft_deal_map.c \
		src/floor_ceiling/ft_floor_ceiling.c \

SRCS_BONUS = src/bonus/cub3d_bonus.c \
		src/bonus/ft_minimap_bonus.c \
		src/info_map/ft_init_struct_map.c \
		src/info_map/ft_get_info.c \
		src/info_map/ft_create_tab_map.c \
		src/info_map/ft_info_map_utils.c \
		src/info_map/ft_info_screen_map.c \
		src/info_map/ft_check_extention.c \
		src/info_map/parsing/ft_alpha_or_digit.c \
		src/info_map/parsing/ft_get_rgb.c \
		src/info_map/parsing/ft_get_path_texture.c \
		src/info_map/parsing/ft_get_resolution.c \
		src/info_map/check_map/ft_check_correct_map.c \
		src/info_map/check_map/ft_check_wall_surrounded.c \
		src/info_map/check_map/ft_check_wall_condition.c \
		src/info_map/check_map/ft_get_orientation.c \
		src/info_map/check_map/ft_utils_check_map.c \
		src/game/ft_init_game.c \
		src/keys/deal_keys.c \
		src/keys/free.c \
		src/save/ft_save.c \
		src/save/ft_check_save_name.c \
		src/rays/ft_init_struc_ray.c \
		src/rays/ft_utils_ray.c \
		src/rays/ft_cast_ray.c \
		src/rays/ft_horz_vert_intersection.c \
		src/rays/ft_cast_all_rays.c \
		src/textures/ft_init_textures.c \
		src/sprites/ft_init_sprite.c \
		src/sprites/ft_sprite.c \
		src/sprites/ft_sort_sprite.c \
		src/sprites/ft_deal_sprite.c \
		src/player/ft_deal_player.c \
		src/player/ft_init_player.c \
		src/player/ft_orientation.c \
		src/map/ft_deal_map.c \
		src/floor_ceiling/ft_floor_ceiling.c \

OBJSRCS = $(SRCS:.c=.o)
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS)
	@rm -rf $(NAME)
	$(MAKE) -C ./libft
	@gcc -o $(NAME) -I include/cub3d.h $(OBJSRCS) $(MLX) ./libft/libft.a -Wall -Wextra -Werror -g
	@echo "\033[33m[Done !]"

all : $(NAME)

bonus : $(OBJSRCSBONUS)
	@rm -rf $(NAME)
	$(MAKE) -C ./libft
	@gcc -o $(NAME) -I include/cub3d.h $(OBJSRCSBONUS) $(MLX) ./libft/libft.a -Wall -Wextra -Werror -g
	@echo "\033[33m[Done !]"

clean :
	rm -rf $(OBJSRCS) 
	rm -rf $(OBJSRCSBONUS)
	rm -rf save.bmp
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all