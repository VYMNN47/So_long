/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahse <abelahse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:21:27 by abelahse          #+#    #+#             */
/*   Updated: 2025/02/10 20:49:32 by abelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static size_t	count_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fix(int n, char *result, size_t i)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			result[0] = '-';
			result[1] = '2';
			n = 147483648;
		}
		else
		{
			result[0] = '-';
			n = -n;
		}
	}
	while (n > 0)
	{
		result[i--] = n % 10 + '0';
		n /= 10;
	}
}

char	*itoa(int n)
{
	size_t	i;
	char	*result;

	i = count_len(n);
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i] = '\0';
	if (n == 0)
		result[0] = '0';
	else
		ft_fix(n, result, i - 1);
	return (result);
}
