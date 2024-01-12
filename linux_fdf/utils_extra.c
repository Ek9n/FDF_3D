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

void draw_line(t_img *img, double x1, double y1, double x2, double y2)
{
	// Iterators, counters required by algorithm
	double x, y, dx, dy, dx1, dy1, px, py, i;
	int xe, ye;
	// Calculate line deltas
	dx = x2 - x1;
	dy = y2 - y1;

	// Create a positive copy of deltas (makes iterating easier)
	dx1 = fabs(dx);
	dy1 = fabs(dy);
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
			xe =x2;
		}
		else
		{ // Line is drawn right to left (swap ends)
			x = x2;
			y = y2;
			xe = x1;
		}
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			img_pix_put(img, x, y, GREEN_PIXEL);
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
			if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
				img_pix_put(img, x, y, GREEN_PIXEL);
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
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			img_pix_put(img, x, y, GREEN_PIXEL);
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
			if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
				img_pix_put(img, x, y, GREEN_PIXEL);
			y++;
		}
	}
}

// void draw_line(t_img *img, int x1, int y1, int x2, int y2)
// {
// 	int dx = abs(x2 - x1);
// 	int dy = abs(y2 - y1);
// 	int sx = (x1 < x2) ? 1 : -1;
// 	int sy = (y1 < y2) ? 1 : -1;
// 	int err = dx - dy;
// 	int err2;

// 	while (!(x1 == x2 && y1 == y2))
// 	{
// 		if (1 >= 0 && x1 <= WIDTH && y1 >= 0 && y1 <= HEIGHT)
// 			img_pix_put(img, x1, y1, GREEN_PIXEL);
// 		err2 = 2 * err;
// 		if (err2 > -dy)
// 		{
// 			err -= dy;
// 			x1 += sx;
// 		}
// 		if (err2 < dx)
// 		{
// 			err += dx;
// 			y1 += sy;
// 		}
// 	}
// }