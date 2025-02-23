/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:57:07 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/11 17:56:23 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

enum		e_keys
{
	ESC_KEY = 65307,
	UP_KEY = 65362,
	DOWN_KEY = 65364,
	LEFT_KEY = 65361,
	RIGHT_KEY = 65363,
	W_KEY = 119,
	A_KEY = 97,
	S_KEY = 115,
	D_KEY = 100
};

typedef struct s_map
{
	char	**map;
	int		colums;
	int		rows;
	int		exit_x;
	int		exit_y;
}			t_map;

typedef struct s_imgs
{
	void	*player;
	void	*coin;
	void	*wall;
	void	*grass;
	void	*exit;
	void	*enemy;
}			t_imgs;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imgs	images;
	t_map	map;
	int		p_x;
	int		p_y;
	int		moves_count;
	int		coin_count;
	int		coin_collected;
}			t_data;

void		free_map(t_map map);
t_map		load_map(char *file);
void		init_window(t_data *data);
void		draw_indx(char indx, t_data *data, int x, int y);
void		draw_img(t_data *data);
void		*load_img(t_data *data, char *path);
void		init_imgs(t_data *data);
void		valid_map(t_map map);
void		free_map(t_map map);
void		move_right(t_data *data);
void		move_left(t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
int			handl_input(int key, t_data *data);
void		free_imgs(t_data *data);
int			close_game(t_data *data);
void		check_win(t_data *data, char *count);
char		*itoa(int n);
void		is_beatable(t_map map);
char		**ft_split(char *s, char c);
size_t		ft_putstr_fd(char *s, int fd);
char		*ft_strrchr(char *s, int c);
void		handle_movement(int key, t_data *data);
void		check_flags(t_map map);
void		validate_map_flags(int plyr, int ext, int coin, t_map map);
void		is_playable(char **visited, t_map map);
int			check_char(char **tmp, char c);
void		free_tmp(char **tmp);
void		handle_map_read_error(char *next_line, char *tmp);

#endif
