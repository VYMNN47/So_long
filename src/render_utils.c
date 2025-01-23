/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:26:29 by abelahse          #+#    #+#             */
/*   Updated: 2025/01/23 13:23:00 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_map(data->map);
		error("couldn't connect to x server.");
	}
	data->win = mlx_new_window(data->mlx,
			data->map.colums * 64,
			data->map.rows * 64, "so_long");
	if (!data->win)
	{
		free_map(data->map);
		free(data->mlx);
		error("couldn't create a new window");
	}
}

void draw_indx(char indx, t_data *data, int x, int y)
{
  if (indx == 'C')
  {
    data->coin_count++;
    mlx_put_image_to_window(data->mlx, data->win, data->images.coin, x, y);
  }
  else if (indx == '0')
    mlx_put_image_to_window(data->mlx, data->win, data->images.grass, x, y);
  else if (indx == '1')
      mlx_put_image_to_window(data->mlx, data->win, data->images.wall, x, y);
  else if (indx == 'P')
  {
    data->p_x = x / 64;
	  data->p_y = y / 64;
	  mlx_put_image_to_window(data->mlx, data->win, data->images.player, x, y);
  }
  else if (indx == 'E')
  {
    data->map.exit_x = x / 64;
    data->map.exit_y = y / 64;
    mlx_put_image_to_window(data->mlx, data->win, data->images.exit, x, y);
  }
}

void draw_img(t_data *data)
{
  int x;
  int y;

  x = 0;
  y = 0;
  data->coin_count = 0;
  data->coin_collected = 0;
  data->moves_count = 0;

  while (data->map.map[y])
  {
    x = 0;
    while(data->map.map[y][x])
    {
      draw_indx(data->map.map[y][x], data, x * 64, y * 64);
      x++;
    }
    y++;
  }
}

void *load_img(t_data *data, char *path)
{
  int x;
  int y;
  void *img;

  img = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
  if (!img)
  {
    img = mlx_new_window(data->mlx, 64, 64, "Error");
    error("Error, Assets are missing");
    return (img);
  }
  return (img);
}

void init_imgs(t_data *data)
{
  data->images.coin = load_img(data, "../textures/imageedit_7_2008711754.xpm");
  data->images.wall = load_img(data, "../textures/imageedit_18_2303292384.xpm");
  data->images.grass = load_img(data, "../textures/imageedit_14_3820093945.xpm");
  data->images.player = load_img(data, "../textures/imageedit_9_2541628732.xpm");
  data->images.exit = load_img(data, "../textures/imageedit_3_2286978979.xpm");
}
