/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_higher_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:58:02 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 09:24:13 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_higher_value(int *data, int *size)
{
	int	i;
	int	v;
	int	v_ret;

	v_ret = -1;
	i = 0;
	while (i < (size[0] * size[1]))
	{
		v = data[i];
		if (v >= v_ret)
			v_ret = v;
		i++;
	}
	return (v_ret);
}
