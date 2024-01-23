/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:05 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/22 15:19:16 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_up(t_game *game)
{
	if (!((game->plot.map[((game->character.y - SPR_SZ)
						/ SPR_SZ)][game->character.x / SPR_SZ]) != '1'))
		return (0);
	else if (!((game->plot.map[((game->character.y - SPR_SZ)
						/ SPR_SZ)][game->character.x / SPR_SZ]) != 'E'))
	{
		if (game->i.collectible == 0)
			return (1);
		return (0);
	}
	return (1);
}

static void	check_up(t_game *game)
{
	if ((game->character.y > SPR_SZ))
	{
		if (is_up(game) != 0)
		{
			game->character.y -= SPR_SZ;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_up(t_game *game)
{
	check_up(game);
	game->character.mem = up;
	mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
		game->character_u.ptr, game->character.x, game->character.y);
	return ;
}
