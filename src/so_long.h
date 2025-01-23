/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:57:07 by abelahse          #+#    #+#             */
/*   Updated: 2025/01/22 18:37:29 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
# include <fcntl.h>
#include "../libft/libft.h"
#include "../libft/gnl/get_next_line.h"


typedef struct s_map
{
	char	**map;
	int		colums;
	int		rows;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_imgs
{
  void *player;
  void *coin;
  void *wall;
  void *grass;
  void *exit;
} t_imgs;

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
}	t_data;

void free_map(t_map map);
t_map load_map(char *file);
void	init_window(t_data *data);
void draw_indx(char indx, t_data *data, int x, int y);
void draw_img(t_data *data);
void *load_img(t_data *data, char *path);
void init_imgs(t_data *data);
void valid_map(t_map map);
void free_map(t_map map);

#endif
