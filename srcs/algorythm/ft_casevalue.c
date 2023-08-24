/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casevalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:03:15 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 09:37:20 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

/* i[0] j[1] k[2] m[3] value[4] */
void	initialization_count_casevalue(int *c, int s_i, int s_j)
{
	c[0] = s_i;
	c[1] = s_j;
	c[2] = 0;
	c[3] = 0;
	c[4] = 0;
}

int	ft_casevalue(char **map, int *i_j, int count, char *ch)
{
	int	c[5];

	initialization_count_casevalue(c, i_j[0], i_j[1]);
	while (c[3] < count)
	{
		c[1] = i_j[1];
		c[2] = 0;
		if (!(map[c[0]]))
			return (-1);
		c[4] = 0;
		while (c[2] < count)
		{
			if (!(map[c[0]][c[1]]) || map[c[0]][c[1]] == ch[1])
				return (-1);
			if (map[c[0]][c[1]] == ch[0])
				c[4]++;
			c[1]++;
			c[2]++;
		}
		c[3]++;
		c[0]++;
	}
	return (c[4]);
}
