/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:01:08 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 18:03:44 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_check(int key_code, t_game *game)
{
	game->character.mem = 0;
	if (key_code == ESC)
		end_game("", game, event_ending);
	else if (key_code == UP)
		move_up(game);
	else if (key_code == DOWN)
		move_down(game);
	else if (key_code == RIGHT)
		move_right(game);
	else if (key_code == LEFT)
		move_left(game);
	return (0);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (game->plot.map[game->character.y / SPR_SZ][game->character.x
		/ SPR_SZ] == 'C')
	{
		game->plot.map[game->character.y / SPR_SZ][game->character.x
			/ SPR_SZ] = '0';
		game->i.collectible--;
	}
	else if (((ft_strchr("N", game->plot.map[game->character.y
						/ 64][(game->character.x + 63) / 64]))))
		end_game(RED "\n\nThe End! you died :( " ENDC, game, -1);
	else if (ft_strchr("N", game->plot.map[game->character.y
				/ 64][(game->character.x) / 64]))
		end_game(RED "\n\nThe End! you died :( " ENDC, game, -1);
	else if (game->plot.map[game->character.y / SPR_SZ][game->character.x
		/ SPR_SZ] == 'E' && game->i.collectible == 0)
	{
		end_game(GREEN "\n\nThe End! :)" ENDC, game, game_over);
	}
	print_map_string(game);
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
	return ;
}
