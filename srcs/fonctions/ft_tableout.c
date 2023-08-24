/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tableout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:41:09 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 16:22:35 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

// Compte le nombre de Newline (\n)
int	ft_lenewline(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 10)
			count++;
		i++;
	}
	return (count);
}

// Output le tableau sous forme table[y][x]
char	**ft_tableout(char *str)
{
	int		lenew;
	char	**table;
	char	charset[1];
	char	*table_str;

	table_str = ft_folderout(str);
	if (!table_str)
		return (0);
	charset[0] = 10;
	lenew = ft_lenewline(table_str);
	table = ft_split(table_str, charset);
	free(table_str);
	return (table);
}
