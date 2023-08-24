/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:12:16 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 16:16:57 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_get_cord(int *data, int higher_value, int *size, int *coord)
{
	int	i;
	int	s;

	s = size[0] * size[1];
	i = 0;
	while (i < (s))
	{
		if (data[i] == higher_value)
		{
			coord[0] = (i / size[1]);
			coord[1] = (i % size[1]);
			return ;
		}
		i++;
	}
}
