/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-mypaint-mael.rabot
** File description:
** free_window.c
*/

#include "../../include/prototype.h"

static int free_ui_button(ui_button_t *ui_button)
{
    free_object(ui_button->color);
    free_object(ui_button->bg_color);
    free_object(ui_button->size_button);
    free_object(ui_button->pencil);
    free_object(ui_button->eraser);
    free(ui_button);
    return 0;
}

static int free_canvas(canvas_t *canvas)
{
    sfTexture_destroy(canvas->foreground_texture);
    sfSprite_destroy(canvas->foreground);
    free(canvas);
    return 0;
}

static int free_welcome_menu(welcome_menu_t *welcome_menu)
{
    free_button(welcome_menu->button);
    sfSprite_destroy(welcome_menu->background);
    sfTexture_destroy(welcome_menu->texture_background);
    free(welcome_menu);
    return 0;
}

int free_window(app_t *app)
{
    free_welcome_menu(app->welcome_menu);
    free_canvas(app->canvas);
    sfRenderWindow_destroy(app->window);
    free_ui_button(app->ui_button);
    free(app->brush);
    free(app);
    return 0;
}
