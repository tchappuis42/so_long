/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 16:59:19 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/18 15:24:13 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mapheight(char *map)
{
	int		l;
	char	*t;
	int		fd;

	l = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_errorfd();
	else
	{
		t = get_next_line(fd);
		if (!t)
		{
			ft_printf("ERROR\nFichier vide");
			exit(0);
		}
		while (t != NULL)
		{
			l++;
			free(t);
			t = get_next_line(fd);
		}
		close (fd);
	}
	return (l);
}

void	ft_makemap(t_data *data)
{
	int		x;
	int		y;
	char	*t;

	y = 0;
	x = 0;
	t = get_next_line(data->m.fd);
	while (t != NULL)
	{
		data->m.map[y] = calloc(strlen(t) + 1, sizeof (char));
		if (!data->m.map[y])
			ft_printf("ERREUR\n");
		while (t[x] != '\0' && t[x] != '\n')
		{
			data->m.map[y][x] = t[x];
			x++;
		}
		x = 0;
		free(t);
		t = NULL;
		t = get_next_line(data->m.fd);
		y++;
	}
}

void	ft_map(t_data *data, char *map)
{
	data->m.win_height = ft_mapheight(map);
	data->m.map = calloc(data->m.win_height + 1, sizeof (char *));
	if (!data->m.map)
		return ;
	data->m.map[data->m.win_height] = 0;
	data->m.fd = open(map, O_RDONLY);
	if (data->m.fd < 0)
		ft_errorfd();
	else
	{
		ft_makemap(data);
		close (data->m.fd);
	}
}
