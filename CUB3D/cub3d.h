/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: broy <broy@student.42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:35:35 by broy              #+#    #+#             */
/*   Updated: 2023/03/05 18:08:19 by broy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define SCREEN_WIDTH 900
# define SCREEN_HEIGHT 900

/* KEYS */

# define WALL		0x00F0F0F0
# define WALKABLE	0x00000000
# define PLAYER	0x00FF0000
# define ESC		65307
# define W		119
# define A		97
# define S		115
# define D		100
# define LEFT		65361
# define RIGHT		65363
# define DOWN		65364
# define UP		65362

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits;
	int		len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_data
{
	t_img			img;
	char			**map;
	unsigned int	floor;
	unsigned int	ceilling;
	void			*mlx;
	void			*win;
	char			**xpm;
	char			**rgb;
	int				minimap_height;
	int				minimap_width;
	int				minimap_y;
	int				minimap_x;
	double			player_x;
	double			player_y;
}		t_data;

int		ft_launch(t_data *data);
void	ft_init(t_data *data);
int		init_colors(t_data *data);
int		ft_parse_info(int fd, t_data *data);
void	ft_parse(char *file, t_data *data);
void	ft_free(char **tab);
void	ft_free_map(char **map);
int		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_minimap(t_data *data);
int		ft_exit(t_data *data);

#endif
