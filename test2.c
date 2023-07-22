#include <math.h>
#include "mlx.h"
#include <stdio.h>

#define PI 3.14159265359
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int draw_line(int beginX, int beginY, int endX, int endY, void *mlx, void *win, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;
    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    if (pixels == 0) {
		mlx_pixel_put(mlx, win, beginX, beginY, color);
        return 0;
    }
    deltaX /= pixels;
    deltaY /= pixels;
	
    double pixelX = beginX;
    double pixelY = beginY;

    while (pixels) {
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
    return 0;
}

int main()
{
    // ... MiniLibX setup ...

    // Draw the angle between 0 and 60 degrees.
	void *mlx_ptr;
    void *mlx_win;

    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "First Ray");
    int center_x = WIN_WIDTH / 2;
    int center_y = WIN_HEIGHT / 2;
    int radius = 100;
    int start_angle = 0; // in degrees
    int end_angle = 60; // in degrees

    double start_angle_rad = (double)start_angle * PI / 180.0;
    double end_angle_rad = (double)end_angle * PI / 180.0;

    int start_x = center_x + (int)(radius * cos(start_angle_rad));
    int start_y = center_y - (int)(radius * sin(start_angle_rad));

    int end_x = center_x + (int)(radius * cos(end_angle_rad));
    int end_y = center_y - (int)(radius * sin(end_angle_rad));

    mlx_clear_window(mlx_ptr, mlx_win); // Clear the window before drawing again.
    mlx_pixel_put(mlx_ptr, mlx_win, center_x, center_y, 0xFFFFFF); // Draw the center point.


	draw_line(center_x, center_y, start_x, start_y,mlx_ptr, mlx_win, 0xFF0000);
	draw_line(center_x, center_y, end_x, end_y, mlx_ptr, mlx_win, 0xFF0000);
    // mlx_line_put(mlx_ptr, mlx_win, center_x, center_y, start_x, start_y, 0xFF0000); // Draw the line from the center to the starting point.
    // mlx_line_put(mlx_ptr, mlx_win, center_x, center_y, end_x, end_y, 0x00FF00); // Draw the line from the center to the ending point.

    mlx_loop(mlx_ptr);
    return 0;
}
