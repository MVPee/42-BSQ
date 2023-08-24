/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_folderout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:36:03 by alexferr          #+#    #+#             */
/*   Updated: 2023/08/23 16:29:43 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	folder_len(char *folder)
{
	int		folder_id;
	char	buffer[1];
	int		count;
	int		re;

	folder_id = open(folder, O_RDONLY);
	if (folder_id == -1)
		return (0);
	re = read(folder_id, buffer, 1);
	count = 1;
	while (re > 0)
	{
		count++;
		re = read(folder_id, buffer, 1);
	}
	if (re == -1)
	{
		close(folder_id);
		return (0);
	}
	close(folder_id);
	return (count);
}

char	*ft_folderout(char *folder)
{
	int		folder_id;
	char	*buffer;
	int		re;

	folder_id = open(folder, O_RDONLY);
	buffer = (char *)malloc((folder_len(folder)) * sizeof(char));
	if (folder_id == -1 || !buffer)
	{
		close(folder_id);
		return (0);
	}
	re = read(folder_id, buffer, folder_len(folder));
	if (re == -1)
	{
		free(buffer);
		close(folder_id);
		return (0);
	}
	buffer[folder_len(folder) - 1] = '\0';
	close(folder_id);
	return (buffer);
}
