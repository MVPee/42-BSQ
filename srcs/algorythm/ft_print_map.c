/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:10:07 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 09:21:23 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_print_map(char **map, int *cord, int count, char *c)
{
	int	j;
	int	i;
	int	k;
	int	m;

	m = 0;
	k = 0;
	j = cord[1];
	i = cord[0] + 1;
	while (m < count)
	{
		j = cord[1];
		k = 0;
		while (k < count)
		{
			if (map[i][j] == c[0])
				map[i][j] = c[2];
			j++;
			k++;
		}
		m++;
		i++;
	}
}
