/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:59:08 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/16 08:42:40 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data)
{
	if (data->map.map[data->p_y][data->p_x + 1] == '1')
		return ;
	data->p_x++;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player, data->p_x
		* 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass, (data->p_x
			- 1) * 64, data->p_y * 64);
}

void	move_left(t_data *data)
{
	if (data->map.map[data->p_y][data->p_x - 1] == '1')
		return ;
	data->p_x--;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player, data->p_x
		* 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass, (data->p_x
			+ 1) * 64, data->p_y * 64);
}

void	move_up(t_data *data)
{
	if (data->map.map[data->p_y - 1][data->p_x] == '1')
		return ;
	data->p_y--;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player, data->p_x
		* 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass, data->p_x
		* 64, (data->p_y + 1) * 64);
}

void	move_down(t_data *data)
{
	if (data->map.map[data->p_y + 1][data->p_x] == '1')
		return ;
	data->p_y++;
	data->moves_count++;
	if (data->map.map[data->p_y][data->p_x] == 'C')
	{
		data->coin_collected++;
		data->map.map[data->p_y][data->p_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win, data->images.player, data->p_x
		* 64, data->p_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.grass, data->p_x
		* 64, (data->p_y - 1) * 64);
}

int	handl_input(int key, t_data *data)
{
	char	*count;

	handle_movement(key, data);
	if (data->map.map[data->p_y][data->p_x] == 'X')
	{
		ft_putstr_fd("\n----->You Lost!", 1);
		close_game(data);
	}
	count = itoa(data->moves_count);
	if (data->p_x == data->map.exit_x && data->p_y == data->map.exit_y)
		check_win(data, count);
	if (data->p_x != data->map.exit_x || data->p_y != data->map.exit_y)
		mlx_put_image_to_window(data->mlx, data->win, data->images.exit,
			data->map.exit_x * 64, data->map.exit_y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->images.wall, 1, 1);
	mlx_string_put(data->mlx, data->win, 32, 32, 0xffffff, count);
	free(count);
	return (0);
}
