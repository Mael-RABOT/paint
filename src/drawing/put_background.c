/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** put_background
*/

#include "../../include/prototype.h"

void set_background_color(sfUint8 *pixels, sfColor color)
{
    for (int i = 0; i < DRAWING_WIDTH * DRAWING_HEIGHT * 4; i += 4) {
        pixels[i] = color.r;
        pixels[i + 1] = color.g;
        pixels[i + 2] = color.b;
        pixels[i + 3] = color.a;
    }
}

void put_background(canvas_t *canvas, sfColor color)
{
    set_background_color(canvas->layer->layer, color);
    sfTexture_updateFromPixels(canvas->layer->rectangle->texture,
        canvas->layer->layer,
        DRAWING_WIDTH, DRAWING_HEIGHT, 0, 0);

    canvas->background = color;
}
