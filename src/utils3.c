/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:16:31 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/15 20:22:16 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_game(data);
	else if (key == RIGHT_KEY || key == D_KEY)
		move_right(data);
	else if (key == LEFT_KEY || key == A_KEY)
		move_left(data);
	else if (key == UP_KEY || key == W_KEY)
		move_up(data);
	else if (key == DOWN_KEY || key == S_KEY)
		move_down(data);
}

void	validate_map_flags(int plyr, int ext, int coin, t_map map)
{
	if ((plyr * ext * coin) != 1)
	{
		free_map(map);
		perror("Error \nInvalid map. P=1, at least C=1, E=1 required.");
		exit(1);
	}
}

void	is_playable(char **visited, t_map map)
{
	if (check_char(visited, 'C'))
	{
		free_map(map);
		free_tmp(visited);
		perror("Error:\n Invalid map.");
		exit(1);
	}
}

void	handle_map_read_error(char *next_line, char *tmp)
{
	free(next_line);
	free(tmp);
	perror("Error");
	exit(1);
}
