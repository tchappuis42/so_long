/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:55:23 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/28 13:56:52 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_grass(t_data *data)
{
	char		*source;
	static void	*img;
	int			img_width;
	int			img_height;

	source = "./xpm/grass2.xpm";
	img = mlx_xpm_file_to_image(data->mlx, source, &img_width, &img_height);
	data->img.grass = img;
}

void	ft_player(t_data *data)
{
	char		*source;
	static void	*img;
	int			img_width;
	int			img_height;

	source = "./xpm/kkr0.xpm";
	img = mlx_xpm_file_to_image(data->mlx, source, &img_width, &img_height);
	data->img.player = img;
}

void	ft_collectable(t_data *data)
{
	char		*src;
	static void	*img;
	int			img_width;
	int			img_height;

	src = "./xpm/objectif.xpm";
	img = mlx_xpm_file_to_image(data->mlx, src, &img_width, &img_height);
	data->img.collectable = img;
}

void	ft_wall(t_data *data)
{
	char		*src;
	static void	*img;
	int			img_width;
	int			img_height;

	src = "./xpm/mur.xpm";
	img = mlx_xpm_file_to_image(data->mlx, src, &img_width, &img_height);
	data->img.wall = img;
}

void	ft_escape(t_data *data)
{
	char		*src;
	static void	*img;
	int			img_width;
	int			img_height;

	src = "./xpm/end1.xpm";
	img = mlx_xpm_file_to_image(data->mlx, src, &img_width, &img_height);
	data->img.escape = img;
}
