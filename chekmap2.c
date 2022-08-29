/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekmap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:29:42 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/28 13:26:56 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_chekber(t_data *data, char *map)
{
	if (ft_strncmp(map + strlen(map) - 4, ".ber", 5) != 0)
	{
		ft_printf("Error\nMauvaise extension de fichier\n");
		ft_freemap(data);
	}
}

void	ft_initdata(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->step = 0;
}
