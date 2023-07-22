/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:16:33 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/22 16:51:27 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FOV_ANGLE 60 // Field of view angle in degrees

typedef struct {
    double x;
    double y;
    double angle;
} Player;

void draw_ray(int x, int y, int color, void *mlx, void *win) {
    mlx_pixel_put(mlx, win, x, y, color);
}

void draw_player(Player player, void *mlx, void *win) {
    int player_size = 5; // Size of the player square
    int color = 0xFF0000; // Color of the player (red)

    int x = player.x - player_size / 2;
    int y = player.y - player_size / 2;
	// mlx_string_put(mlx, win, player.x, player.y, 0xFFFFFF, "+");
    for (int i = 0; i < player_size; i++) {
        for (int j = 0; j < player_size; j++) {
            mlx_pixel_put(mlx, win, x + i, y + j, color);
        }
    }
}

// void draw_player(Player player, void *mlx, void *win) {
//     int player_size = 5; // Size of the player square
//     int color = 0xFF0000; // Color of the player (red)

//     int x = player.x - player_size / 2;
//     int y = player.y - player_size / 2;
//     mlx_string_put(mlx, win, player.x, player.y, 0xFFFFFF, "+");
//     mlx_rectangle(mlx, win, x, y, x + player_size, y + player_size, color);
// }

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

void cast_ray(Player player, double ray_angle, void *mlx, void *win) {
    // Implement raycasting algorithm here to find the intersection point of the ray with walls
    // For simplicity, let's assume the ray intersects the wall at a distance of 100 units from the player.

	// printf("%f\n", ray_angle);
	// exit(1);
    double ray_direction_x = cos(ray_angle);
    double ray_direction_y = sin(ray_angle);

    double wall_distance = 100; // Distance from the player to the wall

    int endpoint_x = player.x + wall_distance * ray_direction_x;
    int endpoint_y = player.y + wall_distance * ray_direction_y;

    int color = 0xFFFFFF; // Color of the ray (white)

    // draw_ray(player.x, player.y, color, mlx, win);
	draw_line(player.x, player.y, endpoint_x, endpoint_y, mlx, win, color);
    // draw_ray(endpoint_x, endpoint_y, color, mlx, win);
}

int main() {
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "First Ray");

    Player player;
    player.x = WINDOW_WIDTH / 2; // Player's starting X position
    player.y = WINDOW_HEIGHT / 2; // Player's starting Y position
    player.angle = (3 * M_PI) / 2 + FOV_ANGLE * (M_PI / 180); // Player's starting angle (facing right)

    draw_player(player, mlx, win);
    // cast_ray(player, player.angle + FOV_ANGLE / 2, mlx, win); // Casting the first ray
    cast_ray(player, player.angle, mlx, win);
    mlx_loop(mlx);

    return 0;
}