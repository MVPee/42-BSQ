/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 00:39:54 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 16:13:13 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int
	ft_ischarset(char c, char *charset)
{
	if (!charset)
		return (0);
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int
	ft_wordc(char *str, char *charset)
{
	int	count;
	int	in_word;

	if (!str || !charset)
		return (0);
	count = 0;
	in_word = 0;
	while (*str)
	{
		if (ft_ischarset(*str, charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int
	ft_wl(char *str, char *charset)
{
	int	length;

	if (!str || !charset)
		return (0);
	length = 0;
	while (*str && !(ft_ischarset(*str, charset)))
	{
		length++;
		str++;
	}
	return (length);
}

// Split une chaine de char (ptr)
char	**ft_split(char *str, char *charset)
{
	int		wordc;
	char	**result;
	int		i;
	int		j;

	i = 0;
	wordc = ft_wordc(str, charset);
	result = (char **)malloc((wordc + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (i < wordc)
	{
		while (ft_ischarset(*str, charset) && *str)
			str++;
		result[i] = (char *)malloc((ft_wl(str, charset) + 1) * sizeof(char));
		if (!result[i])
			return (0);
		j = 0;
		while (*str && !(ft_ischarset(*str, charset)))
			result[i][j++] = *str++;
		result[i][j] = '\0';
		i++;
	}
	result[wordc] = 0; 
	return (result);
}
