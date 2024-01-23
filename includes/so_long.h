/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:51:39 by cyferrei          #+#    #+#             */
/*   Updated: 2024/01/23 15:02:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*all includes*/

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "path.h"
# include "so_long_utils.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

/*strings functions prototypes*/

int			ft_strlen(char *str);
char		*ft_strrchr(const char *str, int searchedChar);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_itoa(int nbr);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);

/*printf functions protoypes*/

int			ft_printf(const char *input, ...);
int			print_char(char c);
int			print_int(int nb);
int			print_string(char *str);
int			print_pointer(unsigned long long ptr);
int			print_unsigned(unsigned int nb);
int			print_hexa(unsigned int nb, const char form);
int			print_percent(void);

/*gnl functions prototypes*/

char		*get_next_line(int fd);
char		*obtain_rest(char *buffer);
char		*extract_line(char *buffer);
static char	*read_file(char *final_buffer, int fd);
char		*ft_strdup_gnl(const char *s);
void		*gnl_calloc(size_t nmeb, size_t size);
char		*gnl_strjoin(char const *s1, char const *s2);
void		*gnl_memcpy(void *dest, const void *src, size_t n);
size_t		gnl_strlen(const char *str);
char		*gnl_strchr(char *s, int c);

/*game functions prototypes*/

void		end_game(char *message, t_game *game, enum e_state i);
void		destroy_image(t_game *game);
void		free_map(t_game *game);
void		init_map(t_game *game, char *path);
int			open_file(char *path);

t_counter	new_counter(void);

bool		is_double_line(char *string_map, int i);
void		is_number_elements_valid(t_game *game, t_counter *cnt, char *tmp);
int			len_map_validation(char **map, t_game *game);

void		parsing_map(t_game *game);
bool		is_surrounded_by_walls(t_game *game, int y, int x);
bool		is_rectangular(t_game *game);
bool		is_valid_character(t_game *game, int y, int x);
void		check_path_player(t_game *game, t_point coord);
void		check_path_collectible(t_game *game, t_point coord);

int			is_valid_position(int i, int j, int y, int x);

char		**copy_map(t_game *game, int y, int x);
char		**allocate_map_memory(t_game *game, int y, int x);
void		free_map_test(char **map, int x);

void		init_window(t_game *game);
void		init_images(t_game *game);
t_image		new_sprite(void *mlx, char *path);
bool		is_not_window_valid(t_game *game);
t_point		get_screen_size(t_game *game);

int			key_check(int key_code, t_game *game);
void		print_moves(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
int			red_cross(t_game *game);
int			mini_maker(t_game *game);
void		player_init(t_game *game);
void		render_map(t_game *game);
void		print_map_string(t_game *game);
void		print_enemies(t_game *game, int y, int x);
void		print_items(t_game *game, int y, int x);

#endif