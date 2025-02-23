/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:51:32 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/16 11:03:47 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_win(t_data *data, char *count)
{
	if (data->coin_collected == data->coin_count)
	{
		ft_putstr_fd("\n----->You won!\n", 1);
		free(count);
		close_game(data);
	}
	ft_putstr_fd("\nYou have to collect all the coins first\n", 1);
}

void	run_game(t_data data)
{
	init_window(&data);
	init_imgs(&data);
	draw_img(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, handl_input, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_game, &data);
	mlx_loop(data.mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		data.map = load_map(av[1]);
		valid_map(data.map);
		run_game(data);
	}
	else
	{
		perror("Error\n Usage ./so_long map.ber");
		return (1);
	}
	return (0);
}
