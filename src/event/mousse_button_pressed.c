/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** mousse_button_pressed
*/

#include "../../include/prototype.h"

void mousse_button_pressed(app_t *app, sfMouseButtonEvent mouse)
{
    pen_down(app, mouse);
}
