/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:32:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 19:30:01 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_img_null(t_game *game)
{
	game->wall.ptr = NULL;
	game->ground.ptr = NULL;
	game->item.ptr = NULL;
	game->item_2.ptr = NULL;
	game->item_3.ptr = NULL;
	game->door_close.ptr = NULL;
	game->door_open.ptr = NULL;
	game->character.ptr = NULL;
	game->character_l.ptr = NULL;
	game->character_r.ptr = NULL;
	game->character_u.ptr = NULL;
	game->monster.ptr = NULL;
	game->monster_2.ptr = NULL;
	game->monster_3.ptr = NULL;
}

void	print_map_string(t_game *game)
{
	char	*string;

	string = ft_itoa(game->i.movements);
	mlx_string_put(game->mlx_pointer, game->windows_pointer, 4,
		((game->plot.height) * 60), 0xFFFFFF, "Movements: ");
	mlx_string_put(game->mlx_pointer, game->windows_pointer, 68,
		((game->plot.height) * 60), 0xFFFFFF, string);
	free(string);
	string = NULL;
	return ;
}

/*function for event "redcross"*/

int	red_cross(t_game *game)
{
	end_game("", game, event_ending);
	return (0);
}

/* mlx function to get screen size*/

t_point	get_screen_size(t_game *game)
{
	t_point	point;

	mlx_get_screen_size(game->mlx_pointer, &point.x, &point.y);
	return (point);
}

/*check if window have a valid size*/

bool	is_not_window_valid(t_game *game)
{
	t_point	screen_size;

	screen_size = get_screen_size(game);
	return (((game->plot.lenght * SPR_SZ) > screen_size.x)
		|| ((game->plot.height * SPR_SZ) > screen_size.y));
}
