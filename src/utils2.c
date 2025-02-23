/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:17 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/04 19:26:33 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (fd < 0 || s == NULL)
		return (0);
	i = write(fd, s, ft_strlen(s));
	return (i);
}

char	*ft_strrchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
