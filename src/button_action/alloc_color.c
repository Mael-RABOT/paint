/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** alloc_color.c
*/

#include "../../include/prototype.h"

void b_alloc_color(app_t *app, int status)
{
    switch (status) {
        case 0:
            app->brush->color = sfBlack; break;
        case 1:
            app->brush->color = sfWhite; break;
        case 2:
            app->brush->color = sfRed; break;
        case 3:
            app->brush->color = sfGreen; break;
        case 4:
            app->brush->color = sfBlue; break;
        case 5:
            app->brush->color = sfYellow; break;
        case 6:
            app->brush->color = sfMagenta; break;
        case 7:
            app->brush->color = sfCyan; break;
    }
}
