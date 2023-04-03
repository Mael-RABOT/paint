/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** update_color
*/

#include "../../include/prototype.h"

void update_color(brush_t *brush, slide_bar_t **array)
{
    brush->color.r = (int)((float)array[0]->value * (float)((float )255 / 100));
    brush->color.g = (int)((float)array[1]->value * (float)((float )255 / 100));
    brush->color.b = (int)((float)array[2]->value * (float)((float )255 / 100));
    brush->color.a = 255;
}
