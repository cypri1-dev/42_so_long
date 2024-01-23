/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:49:14 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/22 14:17:31 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*check if character on map is part of "01CEP"*/

bool	is_valid_character(t_game *game, int y, int x)
{
	if (!(ft_strchr("01CEPN", game->plot.map[y][x])))
		return (false);
	return (true);
}

/*check if map is rectangular*/

bool	is_rectangular(t_game *game)
{
	if (game->plot.lenght == game->plot.height)
		return (false);
	return (true);
}

/*check if map is surrounded by walls*/

bool	is_surrounded_by_walls(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1')
		|| (game->plot.map[0][x] != '1') || (game->plot.map[y][game->plot.lenght
			- 1] != '1') || (game->plot.map[y][0] != '1'))
		return (false);
	return (true);
}

/*check if all mininum requires element are present*/

void	is_number_elements_valid(t_game *game, t_counter *cnt, char *tmp)
{
	if (!(cnt->collectible > 0 && cnt->exit == 1 && cnt->start == 1
			&& cnt->empty > 0))
	{
		free(tmp);
		end_game("Invalide file!", game, file_error);
	}
}

/*check occurrences of two consecutive newline characters*/

bool	is_double_line(char *string_map, int i)
{
	return ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])));
}
