/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:26:45 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/11 15:34:12 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	chars_check(t_map map)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			c = map.map[y][x];
			if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E'
				&& c != 'X')
			{
				free_map(map);
				perror("Error \n Not a valid map, Please try again!");
				exit(1);
			}
			x++;
		}
		y++;
	}
}

static void	check_rec(t_map map)
{
	int	i;

	i = 0;
	while (i < map.rows)
	{
		if (map.colums != (int)ft_strlen(map.map[i]))
		{
			free_map(map);
			perror("Error \n Not a Valid map, Needs to be a rectangle!");
			exit(1);
		}
		i++;
	}
}

static void	wall_check(t_map map)
{
	int	i;

	i = 0;
	while (i < map.colums)
	{
		if (map.map[0][i] != '1' || map.map[map.rows - 1][i] != '1')
		{
			free_map(map);
			perror("Error \n Needs to have Walls all around it");
			exit(1);
		}
		i++;
	}
	i = 1;
	while (i < map.rows - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.colums - 1] != '1')
		{
			free_map(map);
			perror("Error \n Needs to have Walls all around it");
			exit(1);
		}
		i++;
	}
}

void	check_flags(t_map map)
{
	int			plyr;
	int			ext;
	int			i;
	static int	coin;

	plyr = 0;
	ext = 0;
	while (--map.rows)
	{
		i = 0;
		while (*(map.map[map.rows] + i))
		{
			if (*(map.map[map.rows] + i) == 'C')
				coin = 1;
			else if (*(map.map[map.rows] + i) == 'P')
				plyr++;
			else if (*(map.map[map.rows] + i) == 'E')
				ext++;
			i++;
		}
	}
	validate_map_flags(plyr, ext, coin, map);
}

void	valid_map(t_map map)
{
	chars_check(map);
	check_rec(map);
	wall_check(map);
	check_flags(map);
	is_beatable(map);
	if (map.rows > 32 || map.colums > 60)
	{
		free_map(map);
		perror("Error \nInvalid map, too big for screen.");
		exit(1);
	}
}
