/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:39:40 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/23 15:48:08 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*mlx function for render player*/

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
		game->character.ptr, game->character.x, game->character.y);
}

/*mlx function to put image to window*/

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'E')
	{
		game->door_open.x = x * SPR_SZ;
		game->door_open.y = y * SPR_SZ;
		if (game->i.collectible == 0)
		{
			mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
				game->door_open.ptr, (x * SPR_SZ), (y * SPR_SZ));
		}
		else
			mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
				game->door_close.ptr, (x * SPR_SZ), (y * SPR_SZ));
	}
	else if (game->plot.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->wall.ptr, (x * SPR_SZ), (y * SPR_SZ));
	else if (game->plot.map[y][x] == 'C')
		print_items(game, y, x);
	else if (game->plot.map[y][x] == 'N')
		print_enemies(game, y, x);
	else
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->ground.ptr, (x * SPR_SZ), (y * SPR_SZ));
}

/*function to create display's player*/

void	player_init(t_game *game)
{
	t_point	point;

	point.y = 0;
	while (game->plot.map[point.y])
	{
		point.x = 0;
		while (game->plot.map[point.y][point.x])
		{
			if (game->plot.map[point.y][point.x] == 'P')
			{
				game->character.x = (SPR_SZ * point.x);
				game->character.y = (SPR_SZ * point.y);
				render_player(game);
				return ;
			}
			point.x++;
		}
		point.y++;
	}
	return ;
}

/*function to create display from chararcter to images*/

void	render_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			check_map_maker(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	return ;
}

/*function to update current display*/

int	mini_maker(t_game *game)
{
	render_map(game);
	if (game->i.movements == 0)
		player_init(game);
	else if (game->character.mem == down)
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->character.ptr, game->character.x, game->character.y);
	else if (game->character.mem == left)
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->character_l.ptr, game->character_l.x, game->character_l.y);
	else if (game->character.mem == right)
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->character_r.ptr, game->character_r.x, game->character_r.y);
	else if (game->character.mem == up)
		mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
			game->character_u.ptr, game->character_u.x, game->character_u.y);
	return (0);
}
