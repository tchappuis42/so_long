/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:12:15 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/18 15:12:53 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_haut(t_data *data)
{
	if (data->m.map[data->py - 1][data->px] != '1')
	{
		if (data->m.map[data->py - 1][data->px] == 'E')
		{
			if (data->c == 0)
				ft_destroyimg(data);
		}
		else
		{
			if (data->m.map[data->py - 1][data->px] == 'C')
			{
				data->m.map[data->py - 1][data->px] = '0';
				data->c--;
			}
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.grass, data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->py--;
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.player, data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->step++;
			ft_printf("%d\n", data->step);
		}
	}
}

void	ft_droite(t_data *data)
{
	if (data->m.map[data->py][data->px + 1] != '1')
	{
		if (data->m.map[data->py][data->px + 1] == 'E')
		{
			if (data->c == 0)
				ft_destroyimg(data);
		}
		else
		{
			if (data->m.map[data->py][data->px + 1] == 'C')
			{
				data->m.map[data->py][data->px + 1] = '0';
				data->c--;
			}
			mlx_put_image_to_window(data->mlx, data->win, data->img.grass,
				data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->px++;
			mlx_put_image_to_window(data->mlx, data->win, data->img.player,
				data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->step++;
			ft_printf("%d\n", data->step);
		}
	}
}

void	ft_bas(t_data *data)
{
	if (data->m.map[data->py + 1][data->px] != '1')
	{
		if (data->m.map[data->py + 1][data->px] == 'E')
		{
			if (data->c == 0)
				ft_destroyimg(data);
		}
		else
		{
			if (data->m.map[data->py + 1][data->px] == 'C')
			{
				data->m.map[data->py + 1][data->px] = '0';
				data->c--;
			}
			mlx_put_image_to_window(data->mlx, data->win, data->img.grass,
				data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->py++;
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.player, data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->step++;
			ft_printf("%d\n", data->step);
		}
	}
}

void	ft_gauche(t_data *data)
{
	if (data->m.map[data->py][data->px - 1] != '1')
	{
		if (data->m.map[data->py][data->px - 1] == 'E')
		{
			if (data->c == 0)
				ft_destroyimg(data);
		}
		else
		{
			if (data->m.map[data->py][data->px - 1] == 'C')
			{
				data->m.map[data->py][data->px - 1] = '0';
				data->c--;
			}
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.grass, data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->px--;
			mlx_put_image_to_window(data->mlx, data->win,
				data->img.player, data->px * IMG_SIZE, data->py * IMG_SIZE);
			data->step++;
			ft_printf("%d\n", data->step);
		}
	}
}

int	ft_mov(int key, t_data *data)
{
	if (key == 126 || key == 13)
		ft_haut(data);
	else if (key == 124 || key == 2)
		ft_droite(data);
	else if (key == 125 || key == 1)
		ft_bas(data);
	else if (key == 123 || key == 0)
		ft_gauche(data);
	else if (key == 53)
		ft_destroyimg(data);
	return (0);
}
