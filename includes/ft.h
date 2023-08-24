/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-pee <mvan-pee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:17:04 by mvpee             #+#    #+#             */
/*   Updated: 2023/08/23 09:37:48 by mvan-pee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(int out, char *str);
void	ft_get_cord(int *data, int higher_value, int *size, int *coord);
void	ft_print_map(char **map, int *cord, int count, char *c);
char	*ft_strcpy(char *dest, char *src);
char	*read_file(int fd);
char	**ft_split(char *str, char *charset);
char	**ft_tableout(char *str);
char	*ft_folderout(char *folder);
int		ft_strlen(char *str);
int		ft_is_numeric(char c);
int		open_file(const char *map);
int		ft_solve(char **map, int *size, char *character);
int		ft_casevalue(char **map, int *i_j, int count, char *c);
int		ft_higher_value(int *data, int *size);
int		ft_map_validity(char **map, char *character, int *height_width);
void	ft_clearfile(void);
int		ft_createfile(char *str);
int		ft_atoi(char *str, int max);

#endif