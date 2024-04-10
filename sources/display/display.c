/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:30:16 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 16:45:50 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*function from mlx create image from xpm file*/

t_image	new_sprite(t_game *game, char *path)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(game->mlx_pointer, path, &img.x, &img.y);
	if (img.ptr == NULL)
		end_game("Load image failed", game, img_error);
	return (img);
}

/*function to init window with mlx*/

void	init_window(t_game *game)
{
	game->mlx_pointer = mlx_init();
	if (is_not_window_valid(game))
	{
		free_map(game);
		mlx_destroy_display(game->mlx_pointer);
		free(game->mlx_pointer);
		end_game("Map size larger than display resolution!", game, error);
	}
	else
	{
		game->windows_pointer = mlx_new_window(game->mlx_pointer,
				(game->plot.lenght * SPR_SZ), (game->plot.height
					* SPR_SZ), WINDOW_NAME);
	}
}

/*function to init images with mlx*/

void	init_images(t_game *game)
{	
	init_img_null(game);
	game->wall = new_sprite(game, WALL_PATH);
	game->ground = new_sprite(game, GROUND_PATH);
	game->item = new_sprite(game, ITEM_PATH);
	game->item_2 = new_sprite(game, ITEM_PATH_2);
	game->item_3 = new_sprite(game, ITEM_PATH_3);
	game->door_close = new_sprite(game, DOOR_PATH_CLOSE);
	game->door_open = new_sprite(game, DOOR_PATH_OPEN);
	game->character = new_sprite(game, CHARACTER_PATH);
	game->character_l = new_sprite(game, CHARACTER_L_PATH);
	game->character_r = new_sprite(game, CHARACTER_R_PATH);
	game->character_u = new_sprite(game, CHARACTER_U_PATH);
	game->monster = new_sprite(game, MONSTER_PATH);
	game->monster_2 = new_sprite(game, MONSTER_PATH_2);
	game->monster_3 = new_sprite(game, MONSTER_PATH_3);
	return ;
}

void	print_enemies(t_game *game, int y, int x)
{
	static int	i = 0;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->monster.ptr, x * 64, y * 64);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->monster_2.ptr, x * 64, y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->monster_3.ptr, x * 64, y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return ;
}

void	print_items(t_game *game, int y, int x)
{
	static int	i = 0;

	if (i > 0 && i < SPEED)
	{
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->item.ptr, x * 64, y * 64);
	}
	if (i >= SPEED && i < (SPEED * 4))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->item_2.ptr, x * 64, y * 64);
	}
	if (i >= (SPEED * 4) && i < (SPEED * 8))
	{
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->item_3.ptr, x * 64, y * 64);
	}
	if (i == (SPEED * 8))
		i = 0;
	i++;
	return ;
}
