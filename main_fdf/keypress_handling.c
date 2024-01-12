#include "fdf.h"

int handle_keypress(int keysym, t_data *data)
{
	
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (keysym == XK_Control_L)
	{
		// t_xvar xvar;
		// mlx_int_get_visual(&xvar);
		// mlx_mouse_hide(&xvar, &xvar.win_list);
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->safed_mouse_y, &data->safed_mouse_x);
		printf("mousex:%d, mousey:%d\n", data->safed_mouse_x, data->safed_mouse_y);
		data->button_pressed = true;
	}
	if (keysym == XK_Up)
	{
		data->map.a_x += 0.01;
	}
	if (keysym == XK_Down)
	{
		data->map.a_x -= 0.01;
	}
	if (keysym == XK_Left)
	{
		data->map.a_z += 0.01;
	}
	if (keysym == XK_Right)
	{
		data->map.a_z -= 0.01;
	}
	if (keysym == XK_a)
	{
		data->map.a_y += 0.01;
	}
	if (keysym == XK_d)
	{
		data->map.a_y -= 0.01;
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	
	if (keysym == XK_Control_L)
	{
		data->button_pressed = false;
	}
	return (0);
}