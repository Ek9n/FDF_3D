#include "fdf.h"

double get_position(int x1, int x2, int y1, int y2, int x_cur, int y_cur)
{
	double full_dist = hypot(x2 - x1, y2 - y1);
	double dist_to_current = hypot(x_cur - x1, y_cur - y1);
	if (full_dist != 0.0)
	{
		// relative position of a point (x_cur, y_cur)
		// along a line between (x1, y1) and (x2, y2)
		// it is ALWAYS IN A RANGE FROM 0 TO 1
		// printf("dist: %f\n", dist_to_current / full_dist);
		return (dist_to_current / full_dist);
	}
	return 1.0;
}

void draw_base_line(t_img *img, int x1, int y1, int x2, int y2)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	int err2;

	while (!(x1 == x2 && y1 == y2))
	{
		if (1 >= 0 && x1 <= WIDTH && y1 >= 0 && y1 <= HEIGHT)
			img_pix_put(img, x1, y1, gradient_to_int(&img->gradient[1]));
		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void draw_far_line(t_img *img, int x1, int y1, int x2, int y2)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	int err2;

	while (!(x1 == x2 && y1 == y2))
	{
		if (1 >= 0 && x1 <= WIDTH && y1 >= 0 && y1 <= HEIGHT)
			img_pix_put(img, x1, y1, gradient_to_int(&img->gradient[0]));
		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void draw_line(t_img *img, int x1, int y1, int x2, int y2)
{
	int x1_start = x1;
	int y1_start = y1;

	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;
	int err2;

	while (!(x1 == x2 && y1 == y2))
	{
		if (x1 >= 0 && x1 <= WIDTH && y1 >= 0 && y1 <= HEIGHT)
		{
			double position = get_position(x1_start, x2, y1_start, y2, x1, y1);
			// printf("position: %f\n", position);
			//   the gradient will be drawn from the first color to the second color
			//   the first color is the color of the leftmost pixel in the line
			//   the second color is the color of the rightmost pixel in the line
			//   the color of the current pixel is calculated by interpolating between the two colors
			int r = round(img->gradient[0].r * (1 - position) + img->gradient[1].r * position);
			// 1.st time: 222 * -0 + 20 * 0 = -222 + 20 = - 202
			// 2.nd time: 222 * -0.16 + 20 * 0.16 = 208
			// printf("r value: %d\n", r);
			int g = round(img->gradient[0].g * (1 - position) + img->gradient[1].g * position);
			int b = round(img->gradient[0].b * (1 - position) + img->gradient[1].b * position);
			int color = (r << 16) | (g << 8) | b;
			img_pix_put(img, x1, y1, color);
		}

		err2 = 2 * err;
		if (err2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void draw_lines(t_img *img, t_map *map)
{
	int x;
	int y;
	double nx_next;
	double ny_next;
	double nz_next;
	double nx;
	double ny;
	int nz;

	x = 0;
	while (x < map->num_rows)
	{
		y = 0;
		while (y < map->num_cols)
		{
			nx = map->coords[x][y].x + WIDTH / 2;
			ny = map->coords[x][y].y + HEIGHT / 2;
			nz = map->coords[x][y].z;

			if (x < map->num_rows - 1)
			{
				nx_next = map->coords[x + 1][y].x + WIDTH / 2;
				ny_next = map->coords[x + 1][y].y + HEIGHT / 2;
				nz_next = map->coords[x + 1][y].z;
				if (nz == nz_next && nz == 0)
					draw_base_line(img, nx, ny, nx_next, ny_next);
				else if (nz == nz_next)
					draw_far_line(img, nx, ny, nx_next, ny_next);
				else
					draw_line(img, nx, ny, nx_next, ny_next);
			}
			if (y < map->num_cols - 1)
			{
				nx_next = map->coords[x][y + 1].x + WIDTH / 2;
				ny_next = map->coords[x][y + 1].y + HEIGHT / 2;
				nz_next = map->coords[x][y + 1].z;
				if (nz == nz_next && nz == 0)
					draw_base_line(img, nx, ny, nx_next, ny_next);
				else if (nz == nz_next)
					draw_far_line(img, nx, ny, nx_next, ny_next);
				else
					draw_line(img, nx, ny, nx_next, ny_next);
			}
			y++;
		}
		x++;
	}
}

void draw_dots(t_img *img, t_map *map)
{
	double xx, yy;
	int x, y;

	x = 0;

	while (x < map->num_rows)
	{
		y = 0;
		while (y < map->num_cols)
		{
			// z = map->coords[(int)x][(int)y].value;
			xx = map->coords[x][y].x + WIDTH / 2;
			yy = map->coords[x][y].y + HEIGHT / 2;

			if (xx >= 0 && xx <= WIDTH && yy >= 0 && yy <= HEIGHT)
				img_pix_put(img, xx, yy, PURPLE_PIXEL);
			y++;
		}
		x++;
	}
}

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void	put_pix(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

// void draw_3D(int x, int y, int z, t_img *img, t_map *map3D)
// {
// 	double xx, yy, zz;
// 	int x, y, z;

// 	x = 0;

// 	while (x < map->num_rows)
// 	{
// 		y = 0;
// 		while (y < map->num_cols)
// 		{
// 			// z = map->coords[(int)x][(int)y].value;
// 			xx = map->coords[x][y].x + WIDTH / 2;
// 			yy = map->coords[x][y].y + HEIGHT / 2;

// 			if (xx >= 0 && xx <= WIDTH && yy >= 0 && yy <= HEIGHT)
// 				img_pix_put(img, xx, yy, PURPLE_PIXEL);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);

	static double dy;
	static double dx;
	static double prev_dx;
	static double prev_dy;
	// double dy = mouse_y - WIDTH / 2;
	// double dx = mouse_x - HEIGHT / 2;
	static int mouse_x;
	static int mouse_y;

	static double last_a_z;
	static double last_a_x;
	float	rot_speed = 0.008;
	
	if (data->button_pressed)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &mouse_y, &mouse_x);
		printf("m_x:%d, m_y:%d\n", mouse_x, mouse_y);
		
		// if (data->safed_mouse_x != mouse_x || data->safed_mouse_x != mouse_y)
		dx = mouse_x - data->safed_mouse_x;
		dy = mouse_y - data->safed_mouse_y;
		data->map.a_z += (dy - prev_dy) * rot_speed;
		data->map.a_x += (dx - prev_dx) * rot_speed;
	
		prev_dx = dx;
		prev_dy = dy;
	}
	else
	{
		prev_dx = 0;
		prev_dy = 0;		
	}
	
	// if (data->button_pressed)
	// {
	// 	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &mouse_y, &mouse_x);
	// 	dy = mouse_y - data->safed_mouse_y;
	// 	dx = mouse_x - data->safed_mouse_x;
	// 	// static int	last_pos[2];
	// // int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
	// // int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);

	// 	// Calculate the angle using atan2
	// 	double angle_rad = atan2(dy, dx);
	// 	double angle_deg = angle_rad * (180.0 / 3.14159); // Convert radians to degrees


	// //For VIKA: will be short go to sidequest :) ; 
	// //i guess we can now store the value of angle_rad to our struct. Don't go without me please :)

	// 	// Ensure angle is between 0 and 360 degrees
	// 	if (angle_deg < 0)
	// 	{
	// 		angle_deg += 360.0;
	// 	}
	// 	data->map.a_z = angle_rad;
	// 	// data->map.a_x = 0.01;
	// 	// printf("Angle between the points: %.2f degrees\n", angle_deg);
	// }
	if (last_a_z != data->map.a_z || last_a_x != data->map.a_x)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		// data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
		// printf("adress: %p\n", data->img.addr);
		
		cartesian_to_iso(&data->map);
		draw_lines(&data->img, &data->map);
		// draw_dots(&data->img, &data->map);
		last_a_z = data->map.a_z;
		last_a_x = data->map.a_x;
		// printf("a_z: %f, a_x: %f, a_y: %f\n", data->map.a_z * 180 / 3.14159, data->map.a_x * 180 / 3.14159, data->map.a_y * 180 / 3.14159);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	}

	return (0);
}


int loop(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);

	static double dy;
	static double dx;
	static double prev_dx;
	static double prev_dy;
	// double dy = mouse_y - WIDTH / 2;
	// double dx = mouse_x - HEIGHT / 2;
	static int mouse_x;
	static int mouse_y;


	static double last_a_z;
	static double last_a_x;
	float	rot_speed = 0.008;
	
	if (data->button_pressed)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &mouse_y, &mouse_x);
		printf("m_x:%d, m_y:%d\n", mouse_x, mouse_y);
		
		// if (data->safed_mouse_x != mouse_x || data->safed_mouse_x != mouse_y)
		dx = mouse_x - data->safed_mouse_x;
		dy = mouse_y - data->safed_mouse_y;
		data->map3D->a_z += (dy - prev_dy) * rot_speed;
		data->map3D->a_x += (dx - prev_dx) * rot_speed;
	
		prev_dx = dx;
		prev_dy = dy;
	}
	else
	{
		prev_dx = 0;
		prev_dy = 0;		
	}

	if (last_a_z != data->map3D->a_z || last_a_x != data->map3D->a_x)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
		data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
		// printf("adress: %p\n", data->img->addr);


// 		static double r = 50;
// 		for (double i = 0; i < 100; i += 0.1)
// 		{
// 			// Bilder benutzen..objecte...
// 			// einbauen wie lange eine pixelstrecke ist.. von gerade umrechnen zb hier fuer kreis.. kruemmung..
// 			// void	img_pix_put3d(t_data *data, int x, int y, int z, int color)
// 			img_pix_put3d(data, r * cos(i) + 200, r * sin(i) + 400, 200, GREEN_PIXEL);
// 			img_pix_put3d(data, r * cos(i) + 200, r * sin(i) + 400, -200, GREEN_PIXEL);
// 			// img_pix_put3d(&data, r * cos(i) + 200, r * sin(i) + 400, 10, GREEN_PIXEL);
// 			// r += 0.1;
// 			printf("size:%lu\n", data->map3D->size_n);
		
// // x=r\cdot \cos(\phi)+m_1

// // y=r \cdot \sin(\phi)+m_2.
// 			// if (i % 10 == 0)
// 			// img_pix_put(&data.img, i, 100, GREEN_PIXEL);
// 			// else
// 			// img_pix_put(&data.img, i * -1, 100, GREEN_PIXEL);

// 		}
		for (size_t i = 0; i < 300; i++)
		{
				img_pix_put3d(data, 50, 100 + i, 200, GREEN_PIXEL);
				img_pix_put3d(data, 100, 100 + i, 200, GREEN_PIXEL);
		}
			rot_3D(data->map3D);
		// for (int i = 0; i < data->map3D->size_i; i++)
// PRINTFCOORDINATE >>>>>>>>>>>>>>>
		for (size_t i = 0; i < 300; i++)
			prntcoordinatefunctimg_pix_put3d(data, 50, 100 + i, 200, GREEN_PIXEL);

	// img_pix_put(&data->img, 50, 50, GREEN_PIXEL);
			printf("size:%ld\n", data->map3D->size_i);

			// cartesian_to_iso(data->map);
			// draw_lines(&data->img, &data->map);

		}
		last_a_z = data->map3D->a_z;
		last_a_x = data->map3D->a_x;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

// void rotate(t_map *map)
// {
// 	int x;
// 	int y;
// 	int z;
// 	double scale;

// 	scale = 1.0;
// 	x = 0;

// 	map->num_rows = 10;
// 	map->num_cols = 10;
// 	int off_x = map->num_rows / 2;
// 	int off_y = map->num_cols / 2;
	
// 	while (x < map->num_rows)
// 	{
// 		y = 0;
// 		while (y < map->num_cols)
// 		{
// 			z = map->coords[x][y].z;

// 			//printf("off_x: %f, off_y: %f\n", off_x, off_y);
// 			float cos_z = cos(map->a_z);
// 			float sin_z = sin(map->a_z);
// 			float cos_x = cos(map->a_x);
// 			float sin_x = sin(map->a_x);

// 			// map->coords[x][y].x_iso = x * cos(map->a_z) - y * sin(map->a_z);
// 			// map->coords[x][y].y_iso = (x * sin(map->a_z) + y * cos(map->a_z)) * cos(map->a_x) + z * sin(map->a_x);
			
// 			double xx;
// 			double yy;

// 			xx = (x - off_x) * cos_z - (y - off_y) * sin_z;
// 			yy = (x - off_x) * sin_z + (y - off_y) * cos_z;

// 			// rotate around x-axis:
// 			yy = yy * cos_x - z * sin_x;
// 			// z = yy * sin_x + z * cos_x;

// 			map->coords[x][y].x = xx * scale;
// 			map->coords[x][y].y = yy * scale;
// 			// printf("z=%d x=%f y=%f\n", z, map->coords[(int)x][(int)y].x_iso, map->coords[(int)x][(int)y].y_iso);
// 			y++;
// 		}
// 		x++;
// 	}
// }

int main(int argc, char **argv)
{
	static t_data data; //???
	t_color *gradient = gen_gradient();
	char *map_name;
	// (void) argc;

	
/*
	-img als spielfelder in weltgroesse.. alle pixel dareinsetzen? jedes objekt benutzt verschiedene
	pixelput funktionen die es wird der layer gesetzt und daraufhin entweder ein pixel überschrieben,
	oder nicht gesetzt. Der jeweilige upperlayer überschreibt die anderen.
	Es können mehrere Objecte auf einen eigenen Layer gesetzt werden und somit an und ausgeschaltet werden... evtl.

	-Skaling wird durch die pixelputfunktion realisiert, die koordinaten werden skalarmultipliziert, der neue pixel gesetzt
	und der alte gelöscht sofern er geschrieben wurde (Layer).
*/
		// printf("WRONG MAP OR NO MAP :(\n");
		printf("Engine Activated :%d)\n", argc);




		// for (int i = 0; i <)
		// static int n = -1;
		// while (++n < 1000)
		// {
		// 	size_t delay = delay_ms(1000);

		// 	while (delay = delay_ms() < 1000);
		// 	printf(".%ld ", delay);

		// }
		// printf(". .");
		// while (delay_ms() < 1000);
		// // delay_ms(1000);
		// printf(". . .");
		// while (delay_ms() < 1000);
		// // delay_ms(1000);
		// printf("\n");
		// while (delay_ms() < 1000);
		// // printf(".\n");



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
	map_name = ft_strjoin("maps/", argv[1]);
	map_name = ft_spec_strjoin(map_name, ".fdf");

	if (argc == 3)
	{
		read_map(open(map_name, O_RDONLY), &data.map);
		fill_z(open(map_name, O_RDONLY), &data.map);
		free(map_name);
		cartesian_to_iso(&data.map);
		draw_lines(&data.img, &data.map);
		draw_dots(&data.img, &data.map);
		print_gradient(data.img.gradient);
	}
	else
	{
		// int	offset = 100;
		// for (int i = 0; i < 50; i++)
		// 	img_pix_put(&data.img, offset + i, offset, GREEN_PIXEL);
		// for (int i = 0; i < 50; i++)
		// 	img_pix_put(&data.img, offset + i, offset + i, GREEN_PIXEL);
		// for (int i = 0; i < 50; i++)
		// 	img_pix_put(&data.img, offset, offset + i, GREEN_PIXEL);

		// t_coords	*coords;

		// data.map.num_rows = HEIGHT;
		// data.map.num_cols = WIDTH;
		// data.map.coords = malloc(1000 * sizeof(t_coords *));
		// for (int i = 0; i < 1000; i++)
			// data.map.coords[i] = malloc(1000 * sizeof(t_coords));

		// rotate(&data.map, &data);
		// rot_pxl(&data.map, &data);

		
// HIER KREIS
		size_t size = 10000;
		data.map3D = malloc(1 * sizeof(t_map3D));
		data.map3D->coords = malloc(size * sizeof(t_coords));
		data.map3D->max_n = size;
		data.map3D->a_x = 0;
		data.map3D->a_y = 0;
		data.map3D->a_z = 0;

		// static double r = 50;
		// for (double i = 0; i < 100; i += 0.1)
		// {
		// 	// Bilder benutzen..objecte...
		// 	// einbauen wie lange eine pixelstrecke ist.. von gerade umrechnen zb hier fuer kreis.. kruemmung..
		// 	// void	img_pix_put3d(t_data *data, int x, int y, int z, int color)
		// 	img_pix_put3d(&data, r * cos(i) + 200, r * sin(i) + 400, 200, GREEN_PIXEL);
		// 	img_pix_put3d(&data, r * cos(i) + 200, r * sin(i) + 400, -200, GREEN_PIXEL);
		// 	// img_pix_put3d(&data, r * cos(i) + 200, r * sin(i) + 400, 10, GREEN_PIXEL);
		// 	// r += 0.1;
		// 	// printf("size:%lu\n", data.map3D->size_n);
		// 	printf("size:%lu\n", data.map3D->size_i);
		
// x=r\cdot \cos(\phi)+m_1

// y=r \cdot \sin(\phi)+m_2.
			// if (i % 10 == 0)
			// img_pix_put(&data.img, i, 100, GREEN_PIXEL);
			// else
			// img_pix_put(&data.img, i * -1, 100, GREEN_PIXEL);

		// }
		// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	}

	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop_hook(data.mlx_ptr, &loop, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);


	mlx_loop(data.mlx_ptr);

	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	data.win_ptr = NULL;
	free(data.win_ptr);
	free(gradient);
	return (0);
}

// int main()
// {
//     void *mlx_ptr;
//     void *win_ptr;

//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Mein Fenster");

//     // Setzen Sie einen Pixel mit der Farbe 0xFFFFFF (Weiß) an den Koordinaten (100, 100)
//     mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFFFFFF);

//     mlx_loop(mlx_ptr);

//     return 0;
// }

// int main()
// {
// 	static t_data	data;

//     // MinilibX initialisieren und Fenster erstellen
// 	data.mlx_ptr = mlx_init();

//     data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Mein Fenster");


// 		data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
// 		data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
// 		// data.img.gradient = gradient;
// //     // Bild erstellen (Breite: 800, Höhe: 600)
// //     data.img = mlx_new_image(data.mlx_ptr, 800, 600);

// //     // Pixeldaten abrufen
// // 	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
// // 	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
// // /
// //     // Pixel im Bild setzen (Beispiel: x=100, y=200, Farbe: Weiß)
//     int x = 100;
//     int y = 200;
//     int color = 0xFFFFFF;

// //     // Berechnen Sie den Index für den Speicherbereich des Pixels
//     int index = (y * data.img.line_len) + (x * (data.img.bpp / 8));

// //     // Setzen Sie die Pixelwerte
//     data.img.addr[index] = (color & 0xFF0000) >> 16; // R
//     data.img.addr[index + 1] = (color & 0x00FF00) >> 8; // G
//     data.img.addr[index + 2] = color & 0x0000FF; // B


// 	img_pix_put(&data.img, 100, 100, GREEN_PIXEL);
//     // Bild auf das Fenster rendern
// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);

//     // MinilibX-Schleife starten
//     mlx_loop(data.mlx_ptr);

//     // Bild freigeben, wenn es nicht mehr benötigt wird
//     mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);

//     return 0;
// }
