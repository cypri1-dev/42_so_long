/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:44:31 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/18 14:38:44 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_left(t_game *game)
{
	if (!(game->plot.map[(game->character.y / SPR_SZ)][((game->character.x
					- SPR_SZ) / SPR_SZ)] != '1'))
		return (0);
	else if (!(game->plot.map[(game->character.y / SPR_SZ)][((game->character.x
					- SPR_SZ) / SPR_SZ)] != 'E'))
	{
		if (game->i.collectible == 0)
			return (1);
		return (0);
	}
	return (1);
}

static void	check_left(t_game *game)
{
	if ((game->character.x > SPR_SZ))
	{
		if (is_left(game) != 0)
		{
			game->character.x -= SPR_SZ;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_left(t_game *game)
{
	check_left(game);
	game->character.mem = left;
	mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
		game->character_l.ptr, game->character.x, game->character.y);
	return ;
}
