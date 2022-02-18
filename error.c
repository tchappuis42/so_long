/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:11:24 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/18 15:31:02 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freemap(t_data *data)
{
	while(data->m.win_height >= 0)
	{
		free(data->m.map[data->m.win_height]);
		data->m.win_height--;
	}
	free(data->m.map);
	exit(0);
}

int	ft_destroyimg(t_data *data)
{
	while(data->m.win_height >= 0)
	{
		free(data->m.map[data->m.win_height]);
		data->m.win_height--;
	}
	free(data->m.map);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	ft_errorfd()
{
	printf("ERROR\n fd");
	exit(0);
}
