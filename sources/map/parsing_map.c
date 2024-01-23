/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:04:48 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/18 14:21:00 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	map_check(t_game *game, int y, int x)
{
	if (!is_surrounded_by_walls(game, y, x))
		end_game("Map isn't surrounded by walls!", game, map_design_error);
	else if (!is_valid_character(game, y, x))
		end_game("Invald character in map!", game, map_design_error);
	return ;
}

void	parsing_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->plot.map[coord.y])
	{
		coord.x = 0;
		while (game->plot.map[coord.y][coord.x])
		{
			map_check(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	check_path_collectible(game, coord);
	check_path_player(game, coord);
	return ;
}
