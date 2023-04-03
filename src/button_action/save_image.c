/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** save_image.c
*/

#include "../../include/prototype.h"

void b_save_image(app_t *app, int status)
{
    save_image(app);
}

void b_save_as_image(app_t *app, int status)
{
    if (app->save_path != NULL) {
        free(app->save_path);
        app->save_path = NULL;
    }
    save_image(app);
}

void b_load_image(app_t *app, int status)
{
    load_image(app);
}
