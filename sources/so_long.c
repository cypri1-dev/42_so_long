/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:30 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 18:54:18 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_count_char(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*mlx function for init hook*/

static void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->windows_pointer, event, mask, f, game);
}

/*init and launch game*/

static void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	parsing_map(game);
	init_window(game);
	init_images(game);
	render_map(game);
	init_hook(game, KEY_PRESS, KEY_PRESS_MASK, key_check);
	init_hook(game, DESTROY_NOTIF, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_maker);
	mlx_loop(game->mlx_pointer);
}

/*check if input file is .ber*/

static bool	is_input_valid(const char *argv)
{
	char	*str;

	if (ft_count_char(argv, '.') != 1)
		return (false);
	str = ft_strrchr(argv, '.');
	if (str)
		return (ft_strcmp(str, ".ber") == 0);
	return (false);
}

/*check if the file is valid*/

int	main(int argc, char **argv, char **envp)
{
	t_game	game;

	if (!check_env(envp))
		end_game("No env !", &game, env_error);
	if (argc == 2 && !(is_input_valid(argv[1])))
		end_game("Can't open file. The format is not supported !", &game,
			error);
	else if (argc > 2)
		end_game("Can't open multiple files !", &game, error);
	else if (argc == 2 && (is_input_valid(argv[1])))
		init_game(&game, argv[1]);
	end_game("Please specify file name!", &game, error);
	return (0);
}
