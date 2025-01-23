/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_beatable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:15:07 by abelahse          #+#    #+#             */
/*   Updated: 2025/01/20 21:27:52 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void flood_fill(t_map map, int y, int x, char **visited)
{
  if (x < 0 || x >= map.colums || y < 0 || y >= map.rows
      || map.map[y][x] == '1' || visited[y][x] == 'f')
    return ;
  flood_fill(map, y + 1, x, visited);
  flood_fill(map, y - 1, x, visited);
  flood_fill(map, y, x + 1, visited);
  flood_fill(map, y, x - 1, visited);
}

