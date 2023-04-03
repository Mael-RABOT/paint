/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** alloc_color.c
*/

#include "../../include/prototype.h"

void b_alloc_color_bg(app_t *app, int status)
{
    switch (status) {
        case 0:
            put_background(app->canvas, sfWhite); break;
        case 1:
            put_background(app->canvas, sfBlack); break;
        case 2:
            put_background(app->canvas, sfRed); break;
        case 3:
            put_background(app->canvas, sfGreen); break;
        case 4:
            put_background(app->canvas, sfBlue); break;
        case 5:
            put_background(app->canvas, sfYellow); break;
        case 6:
            put_background(app->canvas, sfMagenta); break;
        case 7:
            put_background(app->canvas, sfCyan); break;
    }
}
