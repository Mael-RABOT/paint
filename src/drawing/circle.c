/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** circle
*/

#include "../../include/prototype.h"

static void calcul_circle(canvas_t *canvas, sfVector2f pos,
    circle_info_t *info, sfColor color)
{
    if ((((float)info->i - pos.x - (float)info->radius) * ((float)info->i
    - pos.x - (float)info->radius) + ((float)info->j - pos.y
    - (float)info->radius) * ((float)info->j - pos.y - (float)info->radius))
        <= ((float)info->radius * (float)info->radius)) {
        int index = ((info->i - info->size / 2) + (info->j - info->size / 2)
        * (int)DRAWING_WIDTH) * 4;
        add_pixel(canvas, index, color);
    }
}

static circle_info_t *make_circle_info(int radius, int i, int j, int size)
{
    circle_info_t *info = malloc(sizeof(circle_info_t));
    info->radius = radius;
    info->size = size;
    info->i = i;
    info->j = j;
    return (info);
}

void put_circle(canvas_t *canvas, sfVector2f pos, int size, sfColor color)
{
    circle_info_t *info;
    int radius = size / 2;
    for (int i = (int)pos.x; (float)i < pos.x + (float)size; i++) {
        for (int j = (int)pos.y; (float)j < pos.y + (float)size; j++) {
            info = make_circle_info(radius, i, j, size);
            calcul_circle(canvas, pos, info, color);
        }
    }
    free(info);
}
