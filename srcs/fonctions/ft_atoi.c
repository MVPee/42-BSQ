/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:59:07 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 21:13:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_atoi2(int positive, int step, char *str, int max)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] && i < max)
	{
		if (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && step == 1)
			return (-1);
		else if ((str[i] == 43 || str[i] == 45) && step <= 2)
		{
			return (-1);
			if (str[i] == 45)
				positive *= -1;
		}
		else if ((str[i] >= 48 && str[i] <= 57) && step <= 3)
		{
			step = 3;
			nb = (nb * 10) + (str[i] - '0');
		}
		else
			return (-1);
		i++;
	}
	return (nb * positive);
}

int
	ft_atoi(char *str, int max)
{
	int	a;

	a = ft_atoi2(1, 1, str, max);
	return (a);
}
