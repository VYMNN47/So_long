/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_beatable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:15:07 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/16 11:02:46 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_map map, int y, int x, char **visited)
{
	if (x < 0 || x >= map.colums || y < 0 || y >= map.rows
		|| map.map[y][x] == '1' || visited[y][x] == 'v' || map.map[y][x] == 'X')
		return ;
	visited[y][x] = 'v';
	flood_fill(map, y + 1, x, visited);
	flood_fill(map, y - 1, x, visited);
	flood_fill(map, y, x + 1, visited);
	flood_fill(map, y, x - 1, visited);
}

static char	**tmp_map(t_map map)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (map.rows + 1));
	i = 0;
	while (i < map.rows)
	{
		tmp[i] = malloc(sizeof(char) * (map.colums + 1));
		ft_strcpy(tmp[i], map.map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

int	check_char(char **tmp, char c)
{
	int	x;
	int	y;

	y = 0;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if (tmp[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	is_beatable(t_map map)
{
	char	**visited;
	int		x;
	int		y;

	y = 0;
	while (y < map.rows)
	{
		x = -1;
		while (++x < map.colums)
		{
			if (map.map[y][x] == 'P')
				break ;
		}
		if (map.map[y][x] == 'P')
			break ;
		y++;
	}
	visited = tmp_map(map);
	flood_fill(map, y, x, visited);
	is_playable(visited, map);
	free_tmp(visited);
}
