/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:41:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/22 14:44:14 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_down(t_game *game)
{
	if (!((game->plot.map[((game->character.y + SPR_SZ)
						/ SPR_SZ)][game->character.x / SPR_SZ]) != '1'))
		return (0);
	else if (!((game->plot.map[((game->character.y + SPR_SZ)
						/ SPR_SZ)][game->character.x / SPR_SZ]) != 'E'))
	{
		if (game->i.collectible == 0)
			return (1);
		return (0);
	}
	return (1);
}

static void	check_down(t_game *game)
{
	if (game->character.y < ((game->plot.height * SPR_SZ) - (SPR_SZ * 2)))
	{
		if (is_down(game) != 0)
		{
			game->character.y += SPR_SZ;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

void	move_down(t_game *game)
{
	check_down(game);
	game->character.mem = down;
	mlx_put_image_to_window(game->mlx_pointer, game->windows_pointer,
		game->character.ptr, game->character.x, game->character.y);
	return ;
}
