/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** alloc_brush.c
*/

#include "../../include/prototype.h"

void brush_circle(app_t *app, int status)
{
    app->brush->shape = CIRCLE;
}

void brush_rectangle(app_t *app, int status)
{
    app->brush->shape = RECTANGLE;
}

void brush_normal(app_t *app, int status)
{
    app->brush->shape = SQUARE;
}
