/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createfolder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:20:51 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 21:12:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_strlens(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_createfile(char *str)
{
	int	fd;

	fd = open("inputfolder", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (-1);
	write(fd, str, ft_strlens(str));
	return (fd);
}

void	ft_clearfile(void)
{
	int	fd;

	fd = open("inputfolder", O_WRONLY | O_TRUNC);
	if (fd != -1)
		close(fd);
	close(fd);
}
