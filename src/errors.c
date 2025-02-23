/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:56:03 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/11 14:59:13 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx, data->images.coin);
	mlx_destroy_image(data->mlx, data->images.exit);
	mlx_destroy_image(data->mlx, data->images.grass);
	mlx_destroy_image(data->mlx, data->images.player);
	mlx_destroy_image(data->mlx, data->images.wall);
	mlx_destroy_image(data->mlx, data->images.enemy);
}

int	close_game(t_data *data)
{
	free_imgs(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(0);
	return (0);
}
