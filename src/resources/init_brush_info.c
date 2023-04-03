/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** init_brush_info
*/

#include "../../include/prototype.h"

void add(app_t *app)
{
    app->brush_info = malloc(sizeof(brush_info_t));
    app->brush_info->size_slide = init_slide_bar(
            (sfVector2f)SLIDER_SIZE_POS);
}
