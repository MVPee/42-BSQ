/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:23:16 by mvpee             #+#    #+#             */
/*   Updated: 2023/08/23 21:04:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_freeptrptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != 0)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

//void	ft_createfolder(char *str)


void	process_single_input(int i)
{
	char	buffer[2048];
	int		max;
	int		len_l;
	int		fd;
	char	**map;
	char	character[4];
	int		height_width[2];
	int		re;
	int		x;
	char	ch[3];
	i = 0;
	re = 0;
	re = read(0, buffer, 2047);
	buffer[re] = '\0';
	fd = ft_createfile(buffer);
	if (ft_strlen(buffer) < 4)
	{
		ft_putstr(2, "map error\n");
		return ;
	}
	max = ft_strlen(buffer);
	ch[0] = buffer[max - 4];
	ch[1] = buffer[max - 3];
	max = ft_strlen(buffer) - 3;
	max = ft_atoi(buffer, max - 1);
	if (max == -1)
	{
		ft_putstr(2, "map error\n");
		return ;
	}
	re = read(0, buffer, sizeof(buffer));
	buffer[re] = '\0';
	len_l = re;
	fd = ft_createfile(buffer);
	x = 0;
	while (buffer[x])
	{
		if (buffer[x] != ch[0] || buffer[x] != ch[1])
		{
			ft_putstr(2, "map error\n");
			return ;
		}
		x++;
	}
	i++;
	while (i < max)
	{
		if (re != len_l)
		{
			ft_putstr(2, "map error\n");
			return ;
		}
		re = read(0, buffer, sizeof(buffer));
		buffer[re] = '\0';
		x = 0;
		while (buffer[x])
		{
			if (buffer[x] != ch[0] || buffer[x] != ch[1])
			{
				ft_putstr(2, "map error\n");
				return ;
			}
			x++;
		}
		fd = ft_createfile(buffer);
		i++;
	}
	map = ft_tableout("inputfolder");
	if (!map)
		ft_putstr(2, "map error\n");
	else if (ft_map_validity(map, character, height_width))
	{
		ft_solve(map, height_width, character);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	process_multiple_inputs(int ac, char **av)
{
	char	**map;
	char	character[4];
	int		height_width[2];
	int		i;
	int		v;

	i = 1;
	while (i < ac)
	{
		map = ft_tableout(av[i]);
		if (!map)
			ft_putstr(2, "map error\n");
		else
		{
			if (ft_map_validity(map, character, height_width))
			{
				v = 0;
				ft_solve(map, height_width, character);
				free_map(map);
			}
		}
		i++;
		if (i != ac)
			write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 1)
		process_single_input(0);
	else if (ac > 1)
		process_multiple_inputs(ac, av);
	ft_clearfile();
	return (0);
}
