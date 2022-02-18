/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:02 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/18 15:36:37 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_SIZE 100

# include "mlx/mlx.h"
# include "getnextline/get_next_line.h"
# include "./printf/ft_printf.h"
# include "./printf/libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h> 
# include <math.h>

typedef struct s_image
{
	void	*grass;
	void	*player;
	void	*collectable;
	void	*wall;
	void	*escape;
}		t_image;

typedef struct s_m
{
	int		fd;
	char	**map;
	int		errormap;
	int		win_width;
	int		win_height;
}		t_m;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		c;
	int		e;
	int		p;
	int		px;
	int		py;
	int		step;
	t_m		m;
	t_image	img;
}		t_data;

//fonction creer les sprits
void	ft_grass(t_data *data);
void	ft_player(t_data *data);
void	ft_collectable(t_data *data);
void	ft_wall(t_data *data);
void	ft_escape(t_data *data);

//afficher la map
void	ft_images(t_data *data);
void	ft_printimg(t_data *data, int y, int x);
void	ft_whileimg(t_data *data);

//fonction pour creer la map
void	ft_map(t_data *data, char *map);
int		ft_mapheight(char *map);
void	ft_makemap(t_data *data);

//fonction pour la gestion d'erreur
void	ft_errorfd();
void	ft_chekmap(t_data *data, char *map);
void	ft_chekforme(t_data *data);
void	ft_chekchar(t_data *data);
void	ft_compchar(char c, t_data *data);
void	ft_chek(t_data *data);
void	ft_chekber(t_data *data, char *map);
void	ft_freemap(t_data *data);

//fonction pour les mouvement
int		ft_mov(int key, t_data *data);
void	ft_gauche(t_data *data);
void	ft_bas(t_data *data);
void	ft_droite(t_data *data);
void	ft_haut(t_data *data);
int		ft_destroyimg(t_data *data);
void	ft_initdata(t_data *data);
#endif
