/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:51:05 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/28 14:23:51 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chek(t_data *data)
{
	if (data->p != 1)
	{
		if (data->p == 0)
			ft_printf("Error\nIl faut au moin un player");
		else
			ft_printf("Error\nTrop de player");
		ft_freemap(data);
	}
	if (data->e != 1)
	{
		if (data->e == 0)
			ft_printf("Error\nManque la fin");
		else
			ft_printf("Error\nTrop de fin");
		ft_freemap(data);
	}
	if (data->c == 0)
	{
		ft_printf("Error\nIl faut au moin un collectible");
		ft_freemap(data);
	}
}

void	ft_compchar(char c, t_data *data)
{
	if (c == 'P')
		data->p++;
	else if (c == 'E')
		data->e++;
	else if (c == 'C')
		data->c++;
	else if (c == '1' || c == '0')
		;
	else
	{
		ft_printf("Error\nCaractere inconnu dans la map\n");
		ft_freemap(data);
	}
}

void	ft_chekchar(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->m.map[y] != 0)
	{
		x = 0;
		while (data->m.map[y][x] != 0)
		{
			if (data->m.map[y][x] == 'P')
			{
				data->px = x;
				data->py = y;
			}
			ft_compchar(data->m.map[y][x], data);
			x++;
		}
		y++;
	}
}

void	ft_chekforme(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->m.map[y] != 0)
	{
		x = 0;
		while (data->m.map[y][x] != 0)
		{
			if (data->m.map[0][x] != '1'
				|| data->m.map[data->m.win_height - 1][x] != '1')
			{
				ft_printf("ERROR\nLa map doit etre rectangle, entouré de murs");
				ft_freemap(data);
			}
			else if (data->m.map[y][0] != '1'
				|| data->m.map[y][data->m.win_width - 1] != '1')
			{
				ft_printf("ERROR\nLa map doit etre rectangle, entouré de murs");
				ft_freemap(data);
			}
			x++;
		}
		y++;
	}
}

void	ft_chekmap(t_data *data, char *map)
{
	ft_initdata(data);
	data->m.win_width = strlen(&data->m.map[0][0]);
	ft_chekforme(data);
	ft_chekchar(data);
	ft_chekber(data, map);
	ft_chek(data);
}
