/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** button_type_action
*/

#include "../../include/prototype.h"

void pencil_action(app_t *app, int status)
{
    app->brush->color = app->brush->old_color;
}

void eraser_action(app_t *app, int status)
{
    app->brush->old_color = app->brush->color;
    app->brush->color = sfTransparent;
}
