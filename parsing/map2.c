/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <amiski@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:56:09 by amiski            #+#    #+#             */
/*   Updated: 2023/01/21 16:15:55 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	nbr_v(char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	path_valid(char *s, char **tex)
{
	int	fd;
	char *tmp;

	tmp = ft_strtrim(s, " \t");
	fd = open(tmp, O_RDONLY);
	free(tmp);
	if (fd < 0)
	{
		printf("Error\nbad texture\n");
		free(s);
		return (0);
	}
	close(fd);
	*tex = ft_strtrim(s, " \t\n");
	free(s);
	return (1);
}

int	check_color(char *s, unsigned int *var)
{
	char	**color;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (nbr_v(s) != 2)
	{
		printf("Error\nbad color\n");
		return (0);
	}
	color = ft_split(s, ',');
	while (color[i])
	{
		j = ft_atoi(color[i]);
		tmp = ft_strtrim(color[i], " \t\n");
		if (ft_strlen(tmp) > 3 || j > 255 || j < 0)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		i++;
	}
	*var = (ft_atoi(color[0]) << 16) | (ft_atoi(color[1]) << 8) | \
		(ft_atoi(color[2]));
	free(color[0]);
	free(color[1]);
	free(color[2]);
	free(color);
	free(s);
	return (1);
}

int	ft_ln2d(char **map2d)
{
	int	i;

	i = 0;
	while (map2d[i])
		i++;
	return (i);
}
