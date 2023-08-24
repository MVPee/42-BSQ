/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:58:56 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 18:08:51 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	arg_validity(char *arg)
{
	char	character[4];
	int		map_size;
	int		i;
	int		j;

	if (!arg)
		return (0);
	map_size = 0;
	i = 0;
	while (ft_is_numeric(arg[i]))
		map_size = map_size * 10 + (arg[i++] - '0');
	if (map_size < 1)
		return (0);
	j = 0;
	while (arg[i])
	{
		if (j > 2)
			return (0);
		character[j++] = arg[i++];
	}
	if (character[0] == character[1] || character[0] == character[2]
		|| character[1] == character[2])
		return (0);
	return (map_size);
}

int	map_check(char **map, int size, int width, char *character)
{
	int	i;
	int	j;
	int	current_row_length;

	i = 1;
	j = 0;
	while (map[i])
	{
		current_row_length = 0;
		while (map[i][current_row_length])
			current_row_length++;
		if (current_row_length != width)
			return (1);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != character[0] && map[i][j] != character[1])
				return (1);
			j++;
		}
		i++;
	}
	if (i < size)
		return (1);
	return (0);
}

void	get_character(char *map, char *character)
{
	int	i;

	i = 0;
	while (ft_is_numeric(map[i]))
		i++;
	character[0] = map[i];
	character[1] = map[i + 1];
	character[2] = map[i + 2];
	character[3] = '\0';
}

int	ft_map_validity(char **map, char *character, int *height_width)
{
	int	height;
	int	width;

	height = arg_validity(map[0]);
	if (height < 1)
	{
		ft_putstr(2, "map error\n");
		return (0);
	}
	get_character(map[0], character);
	width = 0;
	while (map[1][width])
		width++;
	if (map_check(map, height, width, character))
	{
		ft_putstr(2, "map error\n");
		return (0);
	}
	height_width[0] = height;
	height_width[1] = width;
	return (1);
}
