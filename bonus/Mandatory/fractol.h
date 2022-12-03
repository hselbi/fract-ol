/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hselbi <hselbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:38:34 by hselbi            #+#    #+#             */
/*   Updated: 2022/04/26 14:30:38 by hselbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*********** key codes  ****************/

//==> exit
# define ESC 53

// ==> to up
# define UP 126
# define W 13

// ==> to down
# define DOWN 125
# define S 1

// ==> to left
# define LEFT 124
# define D 2

// ==> to right
# define RIGHT 123
# define A 0

// ==> add iteration
# define E 14

// ==> substracte iteration
# define R 15

// ==> changing the iteration
# define Z 6

// ==> default of the iteration for julia
# define X 7

// ==> default of the iteration for mandelbrot
# define C 8

/**************** mouse ******************/

// Left click: 1
// Right click: 2
// Middle click: 3
// Scroll up: 4
// Scroll down : 5

/********** headers ************/

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

/********   pixels  ********/

typedef struct s_pxl
{
	double	x;
	double	y;
	double	realx;
	double	realy;
	int		x_ori;
	int		y_ori;
}				t_pxl;

/********   for julia   ********/

typedef struct s_julia
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	color;
	int		max_x;
	int		max_y;
	int		max_inter;
	double	real_xmax;
	double	real_xmin;
	double	real_ymax;
	double	real_ymin;
	double	imag_x;
	double	imag_y;
	double	jzoom;
}			t_julia;

/********   for mandelbrot  *******/

typedef struct s_mandel
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	color;
	int		max_x;
	int		max_y;
	int		max_inter;
	double	real_xmax;
	double	real_xmin;
	double	real_ymax;
	double	real_ymin;

}			t_mandel;

/*******************    libtf   **********************/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);

/*******************    Julia   **********************/

void	julia_set(t_julia vars);
void	pre_julia(t_julia *vars);
void	init_julia(t_julia *vars);
void	julia_draw(t_julia *vast);
void	put_jul_pxls(t_pxl *pxl, t_julia *vast);
int		julia_scheme(t_julia *vast, t_pxl *pxl);
void	julia_iter(t_pxl *pxl, t_julia *vast, int iter);
void	size_check_julia(int arg, char **str);
void	ft_move_keyj(int key, t_julia *vast, long double s_x, long double s_y);
void	my_mlx_julia_put(t_julia *data, int x, int y, int color);
int		jmove_mouse(int x, int y, t_julia *vars);
/*******************    Mandelbrot  *******************/

void	mandelbrot_set(t_mandel vars);
void	init_mandel(t_mandel *vars);
void	pre_mandel(t_mandel *vars);
void	mandel_draw(t_mandel *vars);
void	put_man_pxls(t_pxl *pxl, t_mandel *vars);
int		mandel_scheme(t_mandel *vars, t_pxl *pxl);
int		mandel_mouse_hook(int mousecode, int x_mouse, int y_mouse,
			t_mandel *vars);
void	mandel_iter(t_pxl *pxl, t_mandel *vars, int iter);
void	ft_move_keym(int key, t_mandel *vast, long double s_x, long double s_y);
int		ft_mandel_key(int key, t_mandel *vast);
void	my_mlx_mandel_put(t_mandel *data, int x, int y, int color);

/*******************    hooks   *************************/

//==> julia
int		ft_julia_key(int key, t_julia *vast);
int		julia_mouse_hook(int mousecode, int x_mouse, int y_mouse,
			t_julia *vars);
int		jmove_mouse(int x, int y, t_julia *vars);

void	size_check_mandel(int arg, char **str);
void	size_check_julia(int arg, char **str);

//==> mandelbrot
int		ft_mandel_key(int key, t_mandel *vast);

/*******************    others  ************************/

int		ft_updated(char *str);
void	julia_zoom(t_julia *vars, double range_x, double range_y, int i);
void	mandel_zoom(t_mandel *vars, double range_x, double range_y, int i);

/****************	printing	*****************************/

void	ft_error(void);
void	ft_instractions(void);
void	ft_controls(void);
int		ft_close(t_julia *vars);

#endif
