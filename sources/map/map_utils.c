/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:50:53 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 19:31:41 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	end_game_bis(char *message, t_game *game)
{
	ft_printf(RED "Error\n%s\n" ENDC, message);
	destroy_image(game);
	exit(1);
	return ;
}

/*check if point.x == point.y -- same size --*/

static void	line_validation(char **map, t_game *game)
{
	int		i;
	t_point	point;

	i = 0;
	point.x = 0;
	point.y = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		point.x = ft_strlen(map[i]);
		if (point.x != point.y)
		{
			free_map(game);
			end_game("Invalid file : line are not the same size!", game, error);
		}
		i++;
	}
}

/*function to check len of map*/

int	len_map_validation(char **map, t_game *game)
{
	line_validation(map, game);
	return (ft_strlen(map[0]));
}

/*function to open file*/

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nInvalid file\n");
		exit(1);
	}
	return (fd);
}

/*function to init counter*/

t_counter	new_counter(void)
{
	t_counter	counter;

	counter.empty = 0;
	counter.collectible = 0;
	counter.exit = 0;
	counter.movements = 0;
	counter.start = 0;
	return (counter);
}
