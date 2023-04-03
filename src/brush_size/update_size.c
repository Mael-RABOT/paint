/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** update_size
*/

#include "../../include/prototype.h"

static void square(app_t *app, slide_bar_t **array)
{
    app->brush->size = (int)((float)array[0]->value
        * (float)((float )MAX_BRUSH_SIZE / 100));
    app->brush->size = (app->brush->size < STD_BRUSH_SIZE)
        ? STD_BRUSH_SIZE : app->brush->size;
}

static void rectangle(app_t *app, slide_bar_t **array)
{
    app->brush->rect_size.x = (int)((float)array[0]->value
        * (float)((float )MAX_BRUSH_SIZE / 100));
    app->brush->rect_size.y = (int)((float)array[1]->value
        * (float)((float )MAX_BRUSH_SIZE / 100));
    app->brush->rect_size.x =
        (app->brush->rect_size.x < (sfVector2f)STD_BRUSH_RECT_SIZE.x)
        ? (sfVector2f)STD_BRUSH_RECT_SIZE.x : app->brush->rect_size.x;
    app->brush->rect_size.y =
        (app->brush->rect_size.y < (sfVector2f)STD_BRUSH_RECT_SIZE.y)
        ? (sfVector2f)STD_BRUSH_RECT_SIZE.y : app->brush->rect_size.y;
}

void update_brush(app_t *app, brush_shape_t shape, slide_bar_t **array)
{
    if (shape == SQUARE)
        square(app, array);
    if (shape == RECTANGLE)
        rectangle(app, array);
}
