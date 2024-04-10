/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:17:58 by cyferrei          #+#    #+#             */
/*   Updated: 2024/02/06 18:34:31 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

/*all defines*/

# define RED "\033[1m\033[31m"
# define GREEN "\033[1m\033[32m"
# define ENDC "\033[0m"

# define SPR_SZ 64
# define WINDOW_NAME "./so_long"

# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define SPEED 1

# define KEY_PRESS 02
# define DESTROY_NOTIF 17
# define EXPOSE 12

# define KEY_PRESS_MASK 1
# define EXPOSURE_MASK 32768
# define NO_EVENT_MASK 0

/*all structures*/

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_image
{
	void		*ptr;
	int			*pixels;
	int			line_size;
	int			mem;
	int			x;
	int			y;
	int			movements;
}				t_image;

typedef struct s_draw
{
	char		**map;
	int			height;
	int			lenght;
	char		*line;
}				t_draw;

typedef struct s_counter
{
	int			empty;
	int			collectible;
	int			exit;
	int			start;
	int			movements;
}				t_counter;

typedef struct s_game
{
	void		*mlx_pointer;
	void		*windows_pointer;
	t_counter	i;
	t_draw		plot;
	t_image		character;
	t_image		character_l;
	t_image		character_r;
	t_image		character_u;
	t_image		ground;
	t_image		wall;
	t_image		item;
	t_image		item_2;
	t_image		item_3;
	t_image		door_close;
	t_image		door_open;
	t_image		monster;
	t_image		monster_2;
	t_image		monster_3;
}				t_game;

/*all enums*/

enum			e_state
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
	map_design_error = 5,
	img_error = 6,
	env_error = 7,
};

enum			e_direction
{
	up,
	down,
	left,
	right,
};

#endif