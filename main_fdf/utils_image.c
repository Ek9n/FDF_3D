#include "fdf.h"



void malloc_world(t_map *map)
{
	int i;

	map->coords = malloc(sizeof(t_coords *) * map->num_rows);
	i = 0;
	while (i < map->num_rows)
	{
		map->coords[i] = malloc(sizeof(t_coords) * map->num_cols);
		i++;
	}
}
// void	img_pix_put(t_img *img, int x, int y, int color)
// {
//     char    *pixel;
//     int		i;

//     i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (img->endian != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
//         i -= 8;
//     }
// }

void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (x * img->line_len + y * (img->bpp / 8));
    *(int *)pixel = color;
}

void	set_coord_3d(t_data *data, int x, int y, int z, int color)
{
    // char    *pixel;
	size_t	n = data->map3D->size_i;
	// printf("PrevCoordAddr:%d\n", data->map3D->coords[n]);

	if (data->map3D->size_i < data->map3D->max_n)
	{   
		// pixel = data->img.addr + (x * data->img.line_len + y * (data->img.bpp / 8));
		data->map3D->coords[n].x = x;
		data->map3D->coords[n].y = y;
		data->map3D->coords[n].z = z;
		// *(int *)pixel = color;
		// lastcoordinateaddrhere..
		data->map3D->size_n++;
		data->map3D->size_i++;
	}
	else
		data->map3D->size_i = 0;

}

// void	set_coord_3d(t_data *data, int x, int y, int z, int color)
void	put_coord_3d(t_data *data, int x, int y, int z, int color)
{
	int	i = -1;
	while (++i < data->map3D->size_i)
	{
		if (data->map3D->coords[i].x == x && data->map3D->coords[i].y == y && \
			data->map3D->coords[i].z == z)
			
			// die addresse des bildes in ein 3d array
	}		
    // char    *pixel;
	size_t	n = data->map3D->size_i;
	// printf("PrevCoordAddr:%d\n", data->map3D->coords[n]);

	if (data->map3D->size_i < data->map3D->max_n)
	{   
		// pixel = data->img.addr + (x * data->img.line_len + y * (data->img.bpp / 8));
		data->map3D->coords[n].x = x;
		data->map3D->coords[n].y = y;
		data->map3D->coords[n].z = z;
		// *(int *)pixel = color;
		// lastcoordinateaddrhere..
		data->map3D->size_n++;
		data->map3D->size_i++;
	}
	else
		data->map3D->size_i = 0;

}

// utils_image.c:47:32: error: ‘data->map3D’ is a pointer; did you mean to use ‘->’?
//    47 |         size_t  n = data->map3D.size_n;
//       |                                ^
//       |                                ->
// utils_image.c:49:22: error: invalid type argument of ‘->’ (have ‘t_img’ {aka ‘struct s_img’})
//    49 |     pixel = data->img->addr + (x * data->img->line_len + y * (data->img->bpp / 8));
//       |                      ^~
// utils_image.c:49:45: error: invalid type argument of ‘->’ (have ‘t_img’ {aka ‘struct s_img’})
//    49 |     pixel = data->img->addr + (x * data->img->line_len + y * (data->img->bpp / 8));
//       |                                             ^~
// utils_image.c:49:72: error: invalid type argument of ‘->’ (have ‘t_img’ {aka ‘struct s_img’})
//    49 |     pixel = data->img->addr + (x * data->img->line_len + y * (data->img->bpp / 8));
//       |                                                                        ^~
// utils_image.c:50:31: error: invalid type argument of ‘->’ (have ‘t_coords’ {aka ‘struct s_coords’})
//    50 |         data->map3D->coords[n]->x = x;

// static void	print_square_helper(t_vars *vars, mlx_image_t *img, 
// 		unsigned int size_xy[2], unsigned int offset_xy[2])
// {
// 	unsigned int	tmp_xn;
// 	unsigned int	tmp_yn;
// 	unsigned int	x;
// 	unsigned int	y;

// 	offset_xy[0] *= IMGSIZE;
// 	offset_xy[1] *= IMGSIZE;
// 	tmp_xn = size_xy[0];
// 	tmp_yn = size_xy[1];
// 	x = 0;
// 	y = 0;
// 	while (tmp_yn--)
// 	{
// 		while (tmp_xn--)
// 		{
// 			mlx_image_to_window(vars->mlx, img,
// 				(x * IMGSIZE) + offset_xy[0], (y * IMGSIZE) + offset_xy[1]);
// 			x++;
// 		}
// 		tmp_xn = size_xy[0];
// 		x = 0;
// 		y++;
// 	}
// }

// int	print_square(t_vars *vars, mlx_image_t *img, 
// 		unsigned int size_xy[2], unsigned int offset_xy[2])
// {
// 	bool	flag_malloc;

// 	flag_malloc = false;
// 	if (!size_xy)
// 	{
// 		write(2, "(print_square): No valid size.\n", 31);
// 		return (1);
// 	}
// 	else
// 	{
// 		if (!offset_xy)
// 		{
// 			offset_xy = malloc(2 * sizeof(unsigned int));
// 			offset_xy[0] = 0;
// 			offset_xy[1] = 0;
// 			flag_malloc = true;
// 		}
// 		print_square_helper(vars, img, size_xy, offset_xy);
// 		if (flag_malloc)
// 			free(offset_xy);
// 	}
// 	return (0);
// }

// void	print_time(t_vars *vars)
// {
// 	static bool		flag;
// 	static size_t	secs;
// 	int				delay;
// 	char			*time;
// 	char			*output;

// 	time = ft_itoa(secs / 10);
// 	output = ft_strjoin(" TIME: ", time);
// 	delay = 50;
// 	if (remote_delay_ms(delay))
// 		flag = true;
// 	if (flag == true && !remote_delay_ms(delay))
// 	{
// 		secs++;
// 		if (vars->mlx_outputstring3)
// 			mlx_delete_image(vars->mlx, vars->mlx_outputstring3);
// 		vars->mlx_outputstring3 = 
// 			mlx_put_string(vars->mlx, output, 14 + (vars->size_x / 2) * 
// 			IMGSIZE - 3 * IMGSIZE, vars->size_y * IMGSIZE - IMGSIZE + 30);
// 		set_image_depth(vars->mlx_outputstring3, 12);
// 		flag = false;
// 	}
// 	free(time);
// 	free(output);
// }


int	remote_delay_ms(size_t delay)
{
	size_t			time_us;
	static size_t	time_tmp;
	static size_t	time_cnt;
	struct timeval	tv;

	delay *= 1000;
	gettimeofday(&tv, NULL);
	time_us = tv.tv_usec;
	if (time_tmp > time_us)
		time_cnt += 1000000 - time_tmp + time_us;
	else
		time_cnt += time_us - time_tmp;
	time_tmp = time_us;
	if ((time_cnt % (delay * 2)) < delay)
		return (1);
	return (0);
}


// size_t	delay_ms(int delay)
// {
// 	static bool		flag;
// 	static size_t	counter;

// 	if (remote_delay_ms(delay))
// 		flag = true;
// 	if (flag == true && !remote_delay_ms(delay))
// 	{
// 		counter += 50;
// 		flag = false;
// 	}
// 	return (counter);
// }

size_t	delay_ms(void)
{
	static bool		flag;
	static size_t	counter;
	size_t			delay;

	delay = 10;
	if (remote_delay_ms(delay))
		flag = true;
	if (flag == true && !remote_delay_ms(delay))
	{
		counter += 50;
		flag = false;
	}
	return (counter);
}
