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
# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define SCREEN_WIDTH 900
# define SCREEN_HEIGHT 900
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

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

typedef struct s_var
{
	unsigned int	color;
	double	pos_x;
	double	pos_y;
	int	map_x;
	int	map_y;
	int	hit;
	int	step_x;
	int	step_y;
	int	side;
	int	tex_num;
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	tex_width;
	int	tex_height;
	int	tex_x;
	int	tex_y;
	double	wall_x;
	double	perp_wall_dist;
	double	side_dist_x;
	double	side_dist_y;
	double	cam_x;
	double	ray_x;
	double	ray_y;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	plane_x;
	double	plane_y;
	
}		t_var;

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

typedef struct s_tex
{
	void	*ptr_img;
	int		*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_tex;

typedef struct s_data
{
	t_img			img;
	t_tex			tex[4];
	t_var			var;
	int			texture[4][TEX_HEIGHT * TEX_WIDTH];
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
void	raycast_loop(t_data *data);
int		check_chars(t_data *data);
int		ft_arrlen(char **arr);
int		init_textures(t_data *data);

#endif
