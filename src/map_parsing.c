/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:15 by abelahse          #+#    #+#             */
/*   Updated: 2025/01/23 13:20:15 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(char *file)
{
	char	*ext;
	int		fd;

	ext = ft_strrchr(file, '.');
	if (ext == NULL)
		error("The map doesn't have .ber extention.");
	if (ft_strncmp(ext, ".ber", 4) || *(ext + 4) != '\0')
		error("The map should have only .ber extantion.");
	if ((ft_strlen(file) == 4 && ft_strncmp(file, ".ber", 4) == 0))
		error("Not valid, Hidden file");
  if ((*(ext - 1) == '/' && ft_strncmp(ext, ".ber", 4) == 0))
    error("The map shouldn't be a Directory");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Couldn't open the map");
	return (fd);
}

static char *read_map_from_file(int fd)
{
  char *str_map;
  char *next_line;
  char *tmp;

  str_map = NULL;
  next_line = NULL;
  tmp = get_next_line(fd);
  while (tmp)
  {
    next_line = ft_strjoin(str_map, tmp);
    if (!next_line)
      error("Something wrong happened");
    //free(str_map);
    str_map = next_line;
    if (tmp[0] == '\n')
    {
      free(next_line);
      free(tmp);
      error("Not a valid Map");
    }
    else
      free(tmp);
    tmp = get_next_line(fd);
  }
  return (str_map);
}

static t_map str_to_map(char *str_map)
{
  t_map map;

  map.map = ft_split(str_map, '\n');
  if (!map.map)
    error("An error has occurred");
  map.rows = 0;
  while (map.map[map.rows])
    map.rows++;
  map.colums = ft_strlen(map.map[0]);
  return (map);
}

t_map load_map(char *file)
{
  t_map map;
  char *str_map;
  int fd;

  fd = check_file(file);
  str_map = read_map_from_file(fd);
  map = str_to_map(str_map);
  free(str_map);
  return (map);
}

void free_map(t_map map)
{
  int i;

  i = 0;
  while (map.map[i])
    free(map.map[i++]);
  free(map.map);
}
