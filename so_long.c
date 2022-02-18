/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:47:00 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/18 14:18:25 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.mlx = mlx_init();
		ft_map(&data, argv[1]);
		ft_chekmap(&data, argv[1]);
		data.win = mlx_new_window(data.mlx, data.m.win_width * IMG_SIZE,
				data.m.win_height * IMG_SIZE, "So_Long 42");
		ft_images(&data);
		mlx_key_hook(data.win, ft_mov, &data);
		mlx_hook(data.win, 17, 0, ft_destroyimg, &data);
		mlx_loop(data.mlx);
	}
}
