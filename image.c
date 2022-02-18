/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:25:12 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/14 14:08:12 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printimg(t_data *data, int y, int x)
{
	if (data->m.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, x * IMG_SIZE, y * IMG_SIZE);
	else
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.grass, x * IMG_SIZE, y * IMG_SIZE);
		if (data->m.map[y][x] == 'P')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.player, x * IMG_SIZE, y * IMG_SIZE);
		else if (data->m.map[y][x] == 'C')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.collectable, x * IMG_SIZE, y * IMG_SIZE);
		else if (data->m.map[y][x] == 'E')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.escape, x * IMG_SIZE, y * IMG_SIZE);
	}
}

void	ft_whileimg(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->m.map[y] != 0)
	{
		x = 0;
		while (data->m.map[y][x] != 0)
		{
			ft_printimg(data, y, x);
			x++;
		}
		y++;
	}
}

void	ft_images(t_data *data)
{
	ft_grass(data);
	ft_player(data);
	ft_collectable(data);
	ft_wall(data);
	ft_escape(data);
	ft_whileimg(data);
}
