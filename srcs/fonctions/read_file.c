/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:04:37 by mvpee             #+#    #+#             */
/*   Updated: 2023/08/23 16:09:44 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*read_file(int fd)
{
	char	*result;
	char	buffer[2048];
	ssize_t	octets;

	octets = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (octets <= 0)
	{
		return (0);
	}
	buffer[octets] = '\0';
	result = (char *)malloc((ft_strlen(buffer) + 1) * sizeof(char));
	if (!result)
	{
		return (NULL);
	}
	ft_strcpy(result, buffer);
	return (result);
}
