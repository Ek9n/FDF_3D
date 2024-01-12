#include "fdf.h"

int draw_square(t_img *img)
{
	int side_length = 300;
	int x = WIDTH / 2 - side_length / 2;
	int y = HEIGHT / 2 - side_length / 2;

	int r_range = img->gradient[1].r - img->gradient[0].r;
	int g_range = img->gradient[1].g - img->gradient[0].g;
	int b_range = img->gradient[1].b - img->gradient[0].b;

	int initial_r = img->gradient[0].r;
	int initial_g = img->gradient[0].g;
	int initial_b = img->gradient[0].b;

	for (int i = x; i < x + side_length; i++)
	{
		for (int j = y; j < y + side_length; j++)
		{
			// // the number (0 to 255) will determine the intensity of the red,
			// // green and blue color components
			// int red = 0;
			// // (i - x) ---> horizontal position of the pixel within the square
			// int green = (i - x) * 50 / side_length;
			// // (j - y) ---> vertical position of the pixel within the square
			// int blue = (j - y) * 255 / side_length;

			// Interpolation is a mathematical technique used to estimate values that fall between known values.
			// (i - x): Represents the distance of the current pixel from the left edge of the square.
			// If the pixel is on the left edge, the distance is 0. If the pixel is on the right edge, the distance is side_length - 1.
			int red = initial_r + (i - x) * r_range / side_length;
			int green = initial_g + (i - x) * g_range / side_length;
			// Adds the interpolated value to the initial blue component of the first color in the gradient,
			// which is the blue component of the leftmost pixel in the square.
			// the same is done for the green and red component
			int blue = initial_b + (i - x) * b_range / side_length;

			int color = (red << 16) | (green << 8) | blue;
			img_pix_put(img, i, j, color);
		}
	}
	return (0);
}

void draw_line(t_img *img, int x1, int y1, int x2, int y2)
{
	// Iterators, counters required by algorithm
	int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
	// Calculate line deltas
	dx = x2 - x1;
	dy = y2 - y1;

	// Create a positive copy of deltas (makes iterating easier)
	dx1 = abs(dx);
	dy1 = abs(dy);
	// Calculate error intervals for both axis
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	// The line is X-axis dominant
	if (dy1 <= dx1)
	{
		// Line is drawn left to right
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{ // Line is drawn right to left (swap ends)
			x = x2;
			y = y2;
			xe = x1;
		}
		img_pix_put(img, x + WIDTH / 2, y + HEIGHT / 2, GREEN_PIXEL);
		// Rasterize the line
		for (i = 0; x < xe; i++)
		{
			x = x + 1;
			// Deal with octants...
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			// Draw pixel from line span at
			// currently rasterized position
			img_pix_put(img, x + WIDTH / 2, y + HEIGHT / 2, GREEN_PIXEL);
		}
	}
	else
	{ // The line is Y-axis dominant
		// Line is drawn bottom to top
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{ // Line is drawn top to bottom
			x = x2;
			y = y2;
			ye = y1;
		}
		img_pix_put(img, x + WIDTH / 2, y + HEIGHT / 2, GREEN_PIXEL);
		// Rasterize the line
		for (i = 0; y < ye; i++)
		{
			y = y + 1;
			// Deal with octants...
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			// Draw pixel from line span at
			// currently rasterized position
			img_pix_put(img, x + WIDTH / 2, y + HEIGHT / 2, GREEN_PIXEL);
		}
	}
}

void draw_dots(t_img *img, char **values, int rows, int columns, double a_x, double a_z)
{
	double x;
	double y;
	int z;
	// double offset;
	double scale;
	double x_rotated, z_rotated;

	scale = 15.0;
	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < columns)
		{
			z = values[(int)x][(int)y];
			// double x_offset = columns / 2;
			// double y_offset = rows / 2;

			x_rotated = x * cos(a_z) - y * sin(a_z);
			z_rotated = (x * sin(a_z) + (y)*cos(a_z)) * cos(a_x) - z * sin(a_x);

			x_rotated *= scale;
			z_rotated *= scale;

			// printf("x=%f, x45=%f, y=%f, y45=%f\n", x, x45, y, y45);
			img_pix_put(img, x_rotated + WIDTH / 2, z_rotated + HEIGHT / 2, GREEN_PIXEL);
			y++;
		}
		x++;
	}
}

void cartesian_to_iso(double *iso_x, double *iso_y, char **values, int rows, int columns, double a_x, double a_z)
{
	double x;
	double y;
	int z;
	// double offset;
	double scale;
	double x_rotated, z_rotated;

	scale = 15.0;
	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < columns)
		{
			z = values[(int)x][(int)y];
			// double x_offset = columns / 2;
			// double y_offset = rows / 2;

			x_rotated = x * cos(a_z) - y * sin(a_z);
			z_rotated = (x * sin(a_z) + (y)*cos(a_z)) * cos(a_x) - z * sin(a_x);

			x_rotated *= scale;
			z_rotated *= scale;

			iso_x = &x_rotated;
			iso_y = &z_rotated;
			// printf("x=%f, x45=%f, y=%f, y45=%f\n", x, x45, y, y45);

			y++;
		}
		x++;
	}
}


void loop(t_img *img, t_map *map)
{
	int x;
	int y;
	double x_rotated, y_rotated, x_1_rotated, y_1_rotated;
	int scale;
	int z;

	scale = 10;

	x = 0;
	while (x < map->num_rows)
	{
		y = 0;
		while (y <  map->num_cols)
		{
			z = map->coords[(int)x][(int)y].value;

			x_rotated = x * cos(map->a_z) - y * sin(map->a_z);
			y_rotated = (x * sin(map->a_z) + (y)*cos(map->a_z)) * cos(map->a_x) - z * sin(map->a_x);

			x_rotated *= scale;
			y_rotated *= scale;

			x_1_rotated = (x + 1) * cos(map->a_z) - y * sin(map->a_z);
			y_1_rotated = (x * sin(map->a_z) + (y + 1) * cos(map->a_z)) * cos(map->a_x) - z * sin(map->a_x);

			x_1_rotated *= scale;
			y_1_rotated *= scale;

			if (y == map->num_cols - 1 && x == map->num_rows - 1)
				break;
			if (y == map->num_cols - 1)
			{
				draw_line(img, x_rotated, y_rotated, x_1_rotated, y_rotated);
			}
			else if (x == map->num_rows - 1)
			{
				draw_line(img, x_rotated, y_rotated, x_rotated, y_1_rotated);
			}
			else
			{
				draw_line(img, x_rotated, y_rotated, x_1_rotated, y_rotated);
				draw_line(img, x_rotated, y_rotated, x_rotated, y_1_rotated);
			}

			// if (y == map->num_cols - 1 && x == map->num_rows - 1)
			// 	break;
			// if (y == map->num_cols - 1)
			// {
			// 	draw_line(img, x * scale, y * scale, (x + 1) * scale, y * scale);
			// }
			// else if (x == map->num_rows - 1)
			// {
			// 	draw_line(img, x * scale, y * scale, x * scale, (y + 1) * scale);
			// }
			// else
			// {
			// 	draw_line(img, x * scale, y * scale, (x + 1) * scale, y * scale);
			// 	draw_line(img, x * scale, y * scale, x * scale, (y + 1) * scale);
			// }
			y++;
		}
		x++;
	}
}

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	// draw_square(&data->img);

	static double last_a_z = 0;
	static double last_a_x = 0;
	if (last_a_z != data->map.a_z || last_a_x != data->map.a_x)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	}

	// draw_dots(&data->img, data->map.values, data->map.num_rows, data->map.num_cols, data->map.a_x, data->map.a_z);
	loop(&data->img, &data->map);
	// draw_line(&data->img, 0, 0, 300, 10);
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	last_a_z = data->map.a_z;
	last_a_x = data->map.a_x;
	return (0);
}

int main(void)
{
	static t_data data;
	t_color *gradient = gen_gradient();

	if (gradient == NULL)
		return (MLX_ERROR);

	data.mlx_ptr = mlx_init();

	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "fdf");

	if (data.win_ptr == NULL)
	{
		free(data.win_ptr); // ???
		return (MLX_ERROR);
	}

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	data.img.gradient = gradient;

	// pylone has uneven columns ???
	read_map(open("maps/42.fdf", O_RDONLY), &data.map);
	fill_z(open("maps/42.fdf", O_RDONLY), &data.map);

	print_gradient(data.img.gradient);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);

	free(gradient);
	return (0);
}
