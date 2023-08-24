/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:15:04 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 18:15:50 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

/* i[0] j[1] k[2] count[3] value[4] flag[5] */
void	initialization_count(int *c, int size)
{
	c[0] = 1;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	c[4] = 0;
	c[5] = 1;
	c[6] = size;
}

void	process_map(char **map, char *chr, int *data, int *c)
{
	while (map[c[0]])
	{
		c[1] = 0;
		while (map[c[0]][c[1]])
		{
			c[4] = ft_casevalue(map, c, (c[2]), chr);
			c[5] = 1;
			while (c[2] != (c[6] + 1) && c[5])
			{
				c[4] = ft_casevalue(map, c, (c[2]), chr);
				if (c[4] == -1)
				{
					if (c[2] != 0)
						c[4] = ft_casevalue(map, c, (c[2] - 1), chr);
					c[5] = 0;
				}
				c[2]++;
			}
			c[2] = 0;
			data[c[3]] = c[4];
			c[3]++;
			c[1]++;
		}
		c[0]++;
	}
}

void	print_map(char **map, int *c, int *size)
{
	c[0] = 1;
	c[1] = 0;
	while (map[c[0]] && size[0] >= c[0])
	{
		c[1] = 0;
		while (map[c[0]][c[1]] && size[1] >= c[1])
		{
			write(1, &map[c[0]][c[1]], 1);
			c[1]++;
		}
		write(1, "\n", 1);
		c[0]++;
	}
}

int	ft_solve(char **map, int *size, char *chr)
{
	int	c[7];
	int	coord[2];
	int	*data;
	int	hv;
	int	v;

	initialization_count(c, (size[0] * size[1]));
	data = (int *)malloc((size[0] * size[1]) * sizeof(int));
	process_map(map, chr, data, c);
	hv = ft_higher_value(data, size);
	ft_get_cord(data, hv, size, coord);
	ft_print_map(map, coord, hv, chr);
	print_map(map, c, size);
	v = 0;
	return (0);
}
