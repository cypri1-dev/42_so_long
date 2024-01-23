/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:55:39 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/18 14:29:57 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*function to check if actual position is valid*/

int	is_valid_position(int i, int j, int y, int x)
{
	return (i > 0 && i < y && j > 0 && j < x);
}

char	**allocate_map_memory(t_game *game, int y, int x)
{
	char	**new_map;
	int		j;

	int (i) = 0;
	new_map = (char **)malloc(sizeof(char *) * (game->plot.height + 1));
	if (!new_map)
		return (NULL);
	while (i < y)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (game->plot.lenght + 1));
		if (new_map[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(new_map[j]);
				++j;
			}
			free_map_test(new_map, x);
			return (NULL);
		}
		++i;
	}
	new_map[y] = NULL;
	return (new_map);
}

/*function to copy the orginal map and in order to test it*/

char	**copy_map(t_game *game, int y, int x)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = allocate_map_memory(game, y, x);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			new_map[i][j] = game->plot.map[i][j];
			++j;
		}
		new_map[i][x] = '\0';
		++i;
	}
	return (new_map);
}
