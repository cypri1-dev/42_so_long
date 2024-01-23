/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:12:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/18 14:28:22 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*function to check if there is at leat one valid path between PLAYER and EXIT*/

static int	valid_path_player(char **cpy_map, int i, int j, t_point coord)
{
	int	path_ok;

	path_ok = 0;
	if (cpy_map[i][j] == 'E')
		return (1);
	cpy_map[i][j] = 'V';
	if (is_valid_position(i, j + 1, coord.y, coord.x) && (cpy_map[i][j
			+ 1] == '0' || cpy_map[i][j + 1] == 'C' || cpy_map[i][j
			+ 1] == 'E'))
		path_ok += valid_path_player(cpy_map, i, j + 1, coord);
	if (is_valid_position(i, j - 1, coord.y, coord.x) && (cpy_map[i][j
			- 1] == '0' || cpy_map[i][j - 1] == 'C' || cpy_map[i][j
			- 1] == 'E'))
		path_ok += valid_path_player(cpy_map, i, j - 1, coord);
	if (is_valid_position(i + 1, j, coord.y, coord.x) && (cpy_map[i
				+ 1][j] == '0' || cpy_map[i + 1][j] == 'C' || cpy_map[i
			+ 1][j] == 'E'))
		path_ok += valid_path_player(cpy_map, i + 1, j, coord);
	if (is_valid_position(i - 1, j, coord.y, coord.x) && (cpy_map[i
				- 1][j] == '0' || cpy_map[i - 1][j] == 'C' || cpy_map[i
			- 1][j] == 'E'))
		path_ok += valid_path_player(cpy_map, i - 1, j, coord);
	return (path_ok);
}

/*function to check if there is at leat one valid
path between EACH COLLECTIBLES and PLAYER*/

static int	valid_path_collectible(char **cpy_map, int i, int j, t_point coord)
{
	int	path_ok;

	path_ok = 0;
	if (cpy_map[i][j] == 'P')
		return (1);
	cpy_map[i][j] = 'V';
	if (is_valid_position(i, j + 1, coord.y, coord.x) && (cpy_map[i][j
			+ 1] == '0' || cpy_map[i][j + 1] == 'C' || cpy_map[i][j
			+ 1] == 'P'))
		path_ok += valid_path_collectible(cpy_map, i, j + 1, coord);
	if (is_valid_position(i, j - 1, coord.y, coord.x) && (cpy_map[i][j
			- 1] == '0' || cpy_map[i][j - 1] == 'C' || cpy_map[i][j
			- 1] == 'P'))
		path_ok += valid_path_collectible(cpy_map, i, j - 1, coord);
	if (is_valid_position(i + 1, j, coord.y, coord.x) && (cpy_map[i
				+ 1][j] == '0' || cpy_map[i + 1][j] == 'C' || cpy_map[i
			+ 1][j] == 'P'))
		path_ok += valid_path_collectible(cpy_map, i + 1, j, coord);
	if (is_valid_position(i - 1, j, coord.y, coord.x) && (cpy_map[i
				- 1][j] == '0' || cpy_map[i - 1][j] == 'C' || cpy_map[i
			- 1][j] == 'P'))
		path_ok += valid_path_collectible(cpy_map, i - 1, j, coord);
	return (path_ok);
}

void	free_map_test(char **map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*function to check if there is at least one realisable path beteween player
	- collectibles - exit*/

void	check_path_player(t_game *game, t_point coord)
{
	int		j;
	char	**cpy_map;

	int (i) = 0;
	j = 0;
	while (i < coord.y)
	{
		j = 0;
		while (j < coord.x)
		{
			if (game->plot.map[i][j] == 'P')
			{
				cpy_map = copy_map(game, coord.y, coord.x);
				if (valid_path_player(cpy_map, i, j, coord) == 0)
				{
					free_map_test(cpy_map, coord.y);
					end_game("No path between player - collectibles - exit",
						game, map_char_error);
				}
				free_map_test(cpy_map, coord.y);
			}
			++j;
		}
		++i;
	}
}

void	check_path_collectible(t_game *game, t_point coord)
{
	int		j;
	char	**cpy_map;

	int (i) = 0;
	j = 0;
	while (i < coord.y)
	{
		j = 0;
		while (j < coord.x)
		{
			if (game->plot.map[i][j] == 'C')
			{
				cpy_map = copy_map(game, coord.y, coord.x);
				if (valid_path_collectible(cpy_map, i, j, coord) == 0)
				{
					free_map_test(cpy_map, coord.y);
					end_game("No path between player - collectibles - exit",
						game, map_char_error);
				}
				free_map_test(cpy_map, coord.y);
			}
			++j;
		}
		++i;
	}
}
