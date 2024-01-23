/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:45:08 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/18 12:51:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*function to count numbers of each elements*/

static void	count_elements(t_counter *cnt, char c)
{
	if (c == 'C')
		cnt->collectible++;
	else if (c == 'E')
		cnt->exit++;
	else if (c == 'P')
		cnt->start++;
	else if (c == '0')
		cnt->empty++;
}

/*function to init total count of elements and handles error */

static t_counter	start_counter(char *string_map, t_game *game)
{
	t_counter	cnt;
	int			i;

	i = 0;
	cnt = new_counter();
	while (string_map[i] != '\0')
	{
		if (is_double_line(string_map, i))
		{
			free(string_map);
			end_game("Invalid file!", game, file_error);
		}
		count_elements(&cnt, string_map[i]);
		i++;
	}
	is_number_elements_valid(game, &cnt, string_map);
	return (cnt);
}

/*function to read map line by line with gnl function*/

static void	read_map(t_game *game, int fd)
{
	char	*tmp;

	tmp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		tmp = gnl_strjoin(tmp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = start_counter(tmp, game);
	game->plot.map = ft_split(tmp, '\n');
	free(tmp);
	return ;
}

/*function to init the map and handles some files error :
init numbers of elements check occurence of /n and same size line*/

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_map(game, fd);
	game->plot.lenght = len_map_validation(game->plot.map, game);
	close(fd);
	return ;
}
