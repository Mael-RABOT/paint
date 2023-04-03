/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** put_pixel
*/

#include "../../include/prototype.h"

void add_pixel(canvas_t *canvas, int index, sfColor color)
{
    if (index > 0 && index + 4 < DRAWING_HEIGHT * DRAWING_WIDTH * 4) {
        canvas->selected_layer->layer[index] = color.r;
        canvas->selected_layer->layer[index + 1] = color.g;
        canvas->selected_layer->layer[index + 2] = color.b;
        canvas->selected_layer->layer[index + 3] = color.a;
    }
}

void draw_selector(app_t *app, sfVector2f pos)
{
    switch (app->brush->shape) {
        case SQUARE:
            put_square(app->canvas, pos, (int)app->brush->size,
                app->brush->color);
            break;
        case CIRCLE:
            put_circle(app->canvas, pos, (int)app->brush->size,
                app->brush->color);
            break;
        case RECTANGLE:
            put_rectangle(app->canvas, pos, app->brush->rect_size,
                app->brush->color);
            break;
    }
}
