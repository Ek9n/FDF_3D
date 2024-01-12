#ifndef FDF_H
	#define FDF_H

#include "libs/minilibx-linux/mlx.h"
#include "libs/minilibx-linux/mlx_int.h"
#include "libs/the_libft/libft.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <fcntl.h>
#include <limits.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <time.h>
#include <unistd.h>
// # include "./miniaudio.h"

#define IMGSIZE 64

#define WIDTH 800
#define HEIGHT 600

#define RED_COEFFICIENT 0.2126
#define GREEN_COEFFICIENT 0.7152
#define BLUE_COEFFICIENT 0.0722
#define DARK_THRESHOLD 128
#define BUFFER_SIZE 1024

#define GREEN_PIXEL 0xFF00
#define PURPLE_PIXEL 0xFF00FF
#define MLX_ERROR 1

typedef struct s_color
{
	int r;
	int g;
	int b;
} t_color;

typedef struct s_coords
{
	size_t n;
	void *last_pxl_coord;
	int value;
	double x;
	double y;
	double z;
	double R;
	double a_z;
	double a_x;
	double a_y;
} t_coords;

typedef struct s_map3D
{
	size_t max_n;
	size_t size_n;
	size_t size_i;
	int nx;
	int ny;
	double a_z;
	double a_x;
	double a_y;
	t_coords *coords;
} t_map3D;

typedef struct s_map
{
	int num_rows;
	int num_cols;
	double a_z;
	double a_x;
	double a_y;
	t_coords **coords;
} t_map;

typedef struct s_img
{
	void *mlx_img;
	char *addr;
	int bpp;
	int line_len; //???
	int endian;
	t_color *gradient;
	// t_map map;
} t_img;

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	t_map map;
	t_map3D *map3D;
	int safed_mouse_x;
	int safed_mouse_y;
	bool button_pressed;
} t_data;

// functions
int handle_keypress(int key, t_data *data);
int handle_keyrelease(int keysym, t_data *data);

int is_dark(t_color color);
t_color *gen_gradient(void);
void print_gradient(t_color *gradient);

void img_pix_put(t_img *img, int x, int y, int color);
int gradient_to_int(t_color *color);

// map
void read_map(int fd, t_map *map);
void malloc_for_z(t_map *map);
void fill_z(int fd, t_map *map);
void free_arr2D(char **arr2D);
void cartesian_to_iso(t_map *map);

// Draw
void 	draw_3D(int x, int y, int z, t_img *img, t_map *map3D);

int		remote_delay_ms(size_t delay);
size_t	delay_ms(void);
// size_t	delay_ms(int);
void malloc_world(t_map *map);
// void rotate(t_coords *coords);
// void rotate(t_coords *coords);
void rot_pxl(t_map *map, t_data *data);
void	img_pix_put3d(t_data *data, int x, int y, int z, int color);
void	put_coord_3d(t_data *data, int x, int y, int z, int color);
void	set_coord_3d(t_data *data, int x, int y, int z, int color);
void rot_3D(t_map3D *map3D);


#endif