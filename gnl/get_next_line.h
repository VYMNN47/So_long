/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:35:23 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/04 19:23:15 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*strjoin(char *left, char *buffer);
char	*ft_strcpy(char *dst, char *src);
int	ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
int	ft_strncmp(char *s1, char *s2, size_t n);

#endif
