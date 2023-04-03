/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** mousse_button_released
*/

#include "../../include/prototype.h"

void mousse_button_released(app_t *app, sfMouseButtonEvent mouse)
{
    pen_up(app, mouse);
}
