/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:42:18 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 19:32:33 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_env(char **envp)
{
	const char	*env = "USER";
	char		*val_va;
	int			i;

	val_va = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}

void	free_map(t_game *game)
{
	while (game->plot.height > 0)
	{
		free(game->plot.map[game->plot.height - 1]);
		game->plot.height--;
	}
	free(game->plot.map);
	return ;
}

void	destroy_image_bonus(t_game *game)
{
	if (game)
	{
		if (game->item_2.ptr)
			mlx_destroy_image(game->mlx_pointer, game->item_2.ptr);
		if (game->item_3.ptr)
			mlx_destroy_image(game->mlx_pointer, game->item_3.ptr);
		if (game->character_l.ptr)
			mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
		if (game->character_r.ptr)
			mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
		if (game->character_u.ptr)
			mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
		if (game->monster_2.ptr)
			mlx_destroy_image(game->mlx_pointer, game->monster_2.ptr);
		if (game->monster_3.ptr)
			mlx_destroy_image(game->mlx_pointer, game->monster_3.ptr);
		mlx_destroy_window(game->mlx_pointer, game->windows_pointer);
		mlx_destroy_display(game->mlx_pointer);
		free_map(game);
		free(game->mlx_pointer);
	}
	return ;
}

/*mlx function to destroy images*/

void	destroy_image(t_game *game)
{
	if (game)
	{
		if (game->wall.ptr)
			mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
		if (game->ground.ptr)
			mlx_destroy_image(game->mlx_pointer, game->ground.ptr);
		if (game->item.ptr)
			mlx_destroy_image(game->mlx_pointer, game->item.ptr);
		if (game->door_close.ptr)
			mlx_destroy_image(game->mlx_pointer, game->door_close.ptr);
		if (game->door_open.ptr)
			mlx_destroy_image(game->mlx_pointer, game->door_open.ptr);
		if (game->character.ptr)
			mlx_destroy_image(game->mlx_pointer, game->character.ptr);
		if (game->monster.ptr)
			mlx_destroy_image(game->mlx_pointer, game->monster.ptr);
		destroy_image_bonus(game);
	}
	return ;
}

/*function for ending gaming depending on state*/

void	end_game(char *message, t_game *game, enum e_state i)
{
	if (i == img_error)
	{
		ft_printf(RED "Error\n%s\n" ENDC, message);
		destroy_image(game);
		exit(1);
	}
	else if (i == map_design_error || i == map_char_error)
	{
		free_map(game);
		ft_printf(RED "Error\n%s\n" ENDC, message);
		exit(1);
	}
	else if (i == event_ending || i == game_over)
	{
		ft_printf("%s\n", message);
		destroy_image(game);
		exit(0);
	}
	else if (i == error || i == file_error || i == env_error)
	{
		ft_printf(RED "Error\n%s\n" ENDC, message);
		exit(1);
	}
	end_game_bis(message, game);
}
